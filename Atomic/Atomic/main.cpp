//
//  main.cpp
//  Atomic
//
//  Created by Luciano Almeida on 30/04/20.
//  Copyright © 2020 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <vector>
#include <thread>

std::atomic<int> count = {0};
 
void increment() {
  for (int n = 0; n < 1000; ++n) {
    count.fetch_add(1, std::memory_order_acq_rel);
  }
}

int main(int argc, const char * argv[]) {
  
  std::vector<std::thread> v;
  for (int n = 0; n < 10; ++n) {
    v.emplace_back(increment);
  }
  for (auto& t : v) {
    t.join();
  }
  std::cout << "Count " << count << '\n';
}
