//
//  main.cpp
//  Bitset
//
//  Created by Luciano Almeida on 26/01/20.
//  Copyright © 2020 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <math.h>

enum Options: uint8_t {
  option1 = 1 << 0,
  option2 = 1 << 1,
  option3 = 1 << 2
};

int main(int argc, const char * argv[]) {
  
  // Manual bitmask
  uint8_t mask = 0;
  mask |= option1;
  
  if ((mask & option2) != 0) {
    std::cout << "Mask set: option2" << std::endl;
  } else {
    std::cout << "Mask NOT set: option2" << std::endl;
  }
  
  // std::bitset
  std::bitset<8> set = 0;
  set |= option2;
  std::cout << "bitset: " << set << std::endl;
  
  if (set.test(log2(static_cast<float>(option1)))) {
    std::cout << "Set has option1" << std::endl;
  } else {
    std::cout << "Set NOT has option1" << std::endl;
  }
  
  return 0;
}
