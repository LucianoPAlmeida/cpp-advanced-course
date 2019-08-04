//
//  main.cpp
//  Templates
//
//  Created by Luciano Almeida on 24/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
class Test {
public:
  T i;
  void print() const {
    std::cout << "T: " << this->i << std::endl;
  }
};

template <class T>
void print(T t) {
  std::cout << t << std::endl;
}

void test() {
  std::cout << "Testing" << std::endl;
}

bool matches(std::string s)  {
  return s.size() != 3;
}

template <class Iterator, class T>
int count_if(Iterator begin, Iterator end, bool (*matches)(T))
{
  int count = 0;
  for (; begin != end; ++begin)
    if (matches(*begin))
      ++count;
  return count;
}

// Variadic templates
template <typename T>
T adder(T t) {
  return t;
}

template <typename T, typename ... Args>
T adder(T t, Args ... a) {
  std::cout << __PRETTY_FUNCTION__ << "\n";
  
  return t + adder(a...);
}

template <typename T, typename ... Is>
bool all_equal(Is ... values) {
  std::vector<T> v = { values...};
  if (v.size() <= 1) return true;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] != v[i - 1]) return false;
  }
  return true;
}
template <typename T>
T map(T t) {
  return t;
}
template <typename ... T>
inline void variadic(T ... args) {
  auto list = { map(args)... };
  for (auto element : list) {
    std::cout << element << std::endl;
  }
}

template <typename Head, typename... Tail>
void print(Head const& head, Tail const&... tail){
  std::cout << head;
  if constexpr(sizeof...(tail) > 0) {
    std::cout << ", ";
    print(tail...);
  }
}

template <typename R, typename... T>
R sum(T... args) {
  return (args + ...);
}




int main(int argc, const char * argv[]) {
  Test<int> t;
  t.i = 2;
  t.print();
  
  print(1);
  
  
  // Function pointers
  void (*pF)() = &test;
  void (*tpF)(int) = &print;
  std::function<void (std::string)> fn = &matches;
  
  pF();
  tpF(56);
  
  std::vector<std::string> v;
  v.push_back("two");
  v.push_back("three");
  v.push_back("one");
  
  //    auto count = count_if(v.begin(), v.end(), matches); // Our custom count_if
  auto count = count_if(v.begin(), v.end(), matches);
  
  std::cout << "Count: " << count << std::endl;
  
  // Tuples
  auto tu = std::make_tuple(50, 23, std::string("Hue"));
  std::cout << "1: " << std::get<0>(tu) << ", 2: " << std::get<1>(tu) << ", 3: " << std::get<2>(tu) << std::endl;
  
  std::cout << "Memcpy"<< std::endl;
  
  // Array initializer
  const size_t size = 10;
  std::unique_ptr<int []> a1(new int[size] { [0 ... size - 1] = 5 });
  std::unique_ptr<int []> a2(new int[size] { [0 ... size - 1] = 0 });
  
  memcpy(a2.get(), a1.get(), size * sizeof(int));
  
  for (auto i = 0; i < size; ++i) {
    std::cout << a1[i] << std::endl;
  }
  
  // Variadic templates.
  std::cout << "Adder: " << adder(1, 2, 3, 4, 0) << std::endl;
  
  std::cout << "All equal: " << (all_equal<int>(1, 1, 1, 1, 1) ? "true" : "false") << std::endl;
  
  variadic(1, 2, 3, 4, 5);
  
  print(1, 2, 3, 4);
  
  std::cout << std::endl;
  
  std::cout << "Sum: " << sum<double>(3, 1 , 2, static_cast<float>(1.0), 10) << std::endl;
  
  return 0;
}
