//
//  main.cpp
//  Lists
//
//  Created by Luciano Almeida on 11/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//
#include <array>
#include <iostream>
#include <list>
#include <map>
#include <stdatomic.h>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

class T {
public:
  int i;
  std::string s;
  
  T(int i, std::string s): i(i), s(s) {};
  
  bool operator==(const T &other) const {
    return i == other.i && s == other.s;
  }
};

template<>
struct std::hash<T> {
  std::size_t operator()(const T& k) const {
    
    return std::hash<int>()(k.i) ^ std::hash<std::string>()(k.s);
    
  }
};

int f() {
  return 5;
}

template<typename Iterator>
void dump(Iterator begin, Iterator end) {
  std::for_each(begin, end, [](const auto e) { std::cout << e << ","; });
  std::cout << std::endl;
}

class CCC {
protected:
  std::vector<std::string> v = {"a", "c"};

public:
  const std::vector<std::string> &getV() { return v; }
};

int main(int argc, const char * argv[]) {
  
  //
  std::vector<double> n(20, 1);
  
  std::cout << "Size: " << n.size() << std::endl;
  
  auto capacity = n.capacity();
  
  std::cout << "Capacity: " << capacity << std::endl;
  
  for (int i = 0; i < 10000; i++) {
    if (n.capacity() != capacity) {
      capacity = n.capacity();
      std::cout << "Capacity: " << capacity << std::endl;
    }
    n.push_back(i);
  }
  
  
  
  n.resize(100);
  n.shrink_to_fit();
  
  std::cout << "Capacity: " << n.capacity() << std::endl;
  
  // 2D
  std::vector<std::vector<int>> grid(3, std::vector<int>(3, 0));
  for(int i=0; i< grid.size(); i++) {
    for(int j=0; j < grid[i].size(); j++) {
      grid[i][j] = i + j;
      std::cout << grid[i][j] << " ";
    }
    std::cout << std::endl;
  }
  n.begin() + 1;
  /// List
  std::list<std::string> l;
  
  l.insert(l.begin(), "sfds");
  l.insert(l.begin(), "sfds");
  l.insert(l.begin(), "sfds");
  l.insert(++l.begin(), "second");
  l.push_back("back");
  
  std::for_each(l.begin(), l.end(), [](std::string s) { std::cout << s << std::endl;});
  
  // Multimap
  
  std::multimap<int, std::string> lookup;
  lookup.insert(std::make_pair(1, "one"));
  lookup.insert(std::make_pair(2, "dois"));
  lookup.insert(std::make_pair(2, "duo"));
  lookup.insert(std::make_pair(2, "two"));
  lookup.insert(std::make_pair(3, "three"));
  lookup.insert(std::make_pair(4, "four"));
  
  auto range = lookup.equal_range(3);
  
  for (auto i = range.first; i != range.second; ++i)
  std::cout << i->first << ": " << i->second << '\n';
  
  // Set
  std::set<int> s = {1};
  auto inserted = s.insert(1);
  if (inserted.second) {
    std::cout << *inserted.first << ": " << inserted.second << std::endl;
  }
  
  std::unordered_map<T, int> um;
  auto t1 = T(1, "das");
  um.insert(std::make_pair(t1, 1));
  
  // Std Atomic
  
  atomic_bool b;
  atomic_load(&b);
  atomic_store(&b, true);
  
  std::cout << "bool: " << b << std::endl;
  
  // Stack
  std::stack<int> stk;
  stk.push(1);
  stk.push(2);
  stk.pop();
  
  auto t = stk.top();
  std::cout << "top" << t << std::endl;
  stk.push(6);
  
  while (stk.size() > 0) {
    std::cout << stk.top() << std::endl;
    stk.pop();
  }
  
  std::array<int, 2> values;
  std::array<int, 10> other;
  
  std::fill(other.begin(), other.end(), 0);
  std::fill(values.begin(), values.end(), 1);
  
  std::copy(values.begin(), values.end(), other.begin());
  
  dump(other.begin(), other.end());
  
  return 0;
}

