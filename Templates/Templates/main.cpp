//
//  main.cpp
//  Templates
//
//  Created by Luciano Almeida on 24/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

template <class T> class Test {
public:
  T i;
  void print() const { std::cout << "T: " << this->i << std::endl; }
};

template <class T> void print(T t) { std::cout << t << std::endl; }

void test() { std::cout << "Testing" << std::endl; }

bool matches(std::string s) { return s.size() != 3; }

template <class Iterator, class T>
int count_if(Iterator begin, Iterator end, bool (*matches)(T)) {
  int count = 0;
  for (; begin != end; ++begin)
    if (matches(*begin))
      ++count;
  return count;
}

// Variadic templates
template <typename T> T adder(T t) { return t; }

template <typename T, typename... Args> T adder(T t, Args... a) {
  std::cout << __PRETTY_FUNCTION__ << "\n";

  return t + adder(a...);
}

template <typename T, typename... Is> bool all_equal(Is... values) {
  std::vector<T> v = {values...};
  if (v.size() <= 1)
    return true;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] != v[i - 1])
      return false;
  }
  return true;
}
template <typename T> T map(T t) { return t; }
template <typename... T> inline void variadic(T... args) {
  auto list = {map(args)...};
  for (auto element : list) {
    std::cout << element << std::endl;
  }
}

template <typename Head, typename... Tail>
void print(Head const &head, Tail const &... tail) {
  std::cout << head;
  if constexpr (sizeof...(tail) > 0) {
    std::cout << ", ";
    print(tail...);
  }
}

template <typename R, typename... T> R sum(T... args) { return (args + ...); }

struct Point {
public:
  int x;
  int y;

  Point(int x, int y) : x(x), y(y) {}
};

// Cooool feature \o/
class A {};

class B {
public:
  B() {}
  B(A SL) {}
};

void testFunction(B SR) {}


// TMP
template <int n>
struct incremented {
  static const int value = n + 1;
};

template <unsigned int n>
struct factorial {
  static const int value = n * factorial<n - 1>::value;
};

template <>
struct factorial<0> {
  static const int value = 1;
};

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value,
                                              bool>::type = true>
T addArithmetic(T a, T b) {
  return a + b;
}

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value,
                                              bool>::type = true>
double divide(T a, T b) {
  return a / (double)b;
}

int main(int argc, const char *argv[]) {
  Test<int> t;
  t.i = 2;
  t.print();

  print(1);

  A sl;
  // Since B has a constructor that takes a value of type A C++,
  // compiler implicitly makes the call for it.
  // So we a are able to pass A directly to a function that takes B.
  testFunction(sl);

  // Function pointers
  void (*pF)() = &test;
  void (*tpF)(int) = &print;
  std::function<void(std::string)> fn = &matches;

  pF();
  tpF(56);

  std::vector<std::string> v;
  v.push_back("two");
  v.push_back("three");
  v.push_back("one");

  //    auto count = count_if(v.begin(), v.end(), matches); // Our custom
  //    count_if
  auto count = count_if(v.begin(), v.end(), matches);

  std::cout << "Count: " << count << std::endl;

  // Tuples
  auto tu = std::make_tuple(50, 23, std::string("Hue"));
  std::cout << "1: " << std::get<0>(tu) << ", 2: " << std::get<1>(tu)
            << ", 3: " << std::get<2>(tu) << std::endl;

  std::cout << "Memcpy" << std::endl;

  // Array initializer
  const size_t size = 10;
  std::unique_ptr<int[]> a1(new int[size]{[0 ... size - 1] = 5});
  std::unique_ptr<int[]> a2(new int[size]{[0 ... size - 1] = 0});

  memcpy(a2.get(), a1.get(), size * sizeof(int));

  for (auto i = 0; i < size; ++i) {
    std::cout << a1[i] << std::endl;
  }

  // Variadic templates.
  std::cout << "Adder: " << adder(1, 2, 3, 4, 0) << std::endl;

  std::cout << "All equal: "
            << (all_equal<int>(1, 1, 1, 1, 1) ? "true" : "false") << std::endl;

  variadic(1, 2, 3, 4, 5);

  print(1, 2, 3, 4);

  std::cout << std::endl;

  std::cout << "Sum: " << sum<double>(3, 1, 2, static_cast<float>(1.0), 10)
            << std::endl;

  std::vector<Point> vp = {{1, 2}, {0, 5}};

  //  std::sort(vp.begin(), vp.end(), std::less<>()); Fails to compile unless we
  //  define the compare operator on Point.

  std::sort(vp.begin(), vp.end(),
            [](const auto &p1, const auto &p2) { return p1.x > p2.x; });

  // TMP
  std::cout << incremented<1>::value << std::endl;
  std::cout << "factorial: " << factorial<5>::value << std::endl;
  
  static_assert(factorial<5>::value == 120, "compile-time check");

  // Constraining templates
  // std::enable_if
  uint8_t a = 3;
  uint8_t b = 5;
  auto r = addArithmetic(
      a, b); // Ok uint8_t satisfy the std::is_integral constraint.
  // auto r1 = addArithmetic("a", "b"); //Invalid no matching call requirement
  // 'std::is_arithmetic<const char *>::value' was not satisfied [with T = const
  // char *]
  auto rd = divide(1, 2);
  std::cout << "tmpl: " << r << std::endl;
  std::cout << "tmpl decltype: " << rd << std::endl;

  return 0;
}
