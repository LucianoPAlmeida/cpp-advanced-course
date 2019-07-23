//
//  main.cpp
//  S3L7
//
//  Created by Luciano Almeida on 17/02/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <fstream>

class Parent {
public:
  virtual std::string name() const { return "Parent"; }
};

class Child: public Parent {
public:
  std::string name() const { return "Child"; }
};

enum class Enum: uint8_t {
  CASE1 = 1,
  CASE2 = 2
};

const Parent get() {
  return std::move(Child());
}

void test(const void * data) {
  auto value = *(static_cast<const uint8_t*>(data));
  std::cout << "Enum: " << std::to_string(value) << std::endl;
}

int main(int argc, const char * argv[]) {
  
  auto p1 = get();
  auto c1 = Child();
  Parent* c2 = new Child();
  
  std::cout << "p1: " << p1.name() << std::endl;
  std::cout << "c1: " << c1.name() << std::endl;
  std::cout << "c2: " << c2->name() << std::endl;
  
  std::fstream f;
  f.open("./text.txt", std::fstream::app);
  if (f.is_open()) {
    f << "Hue" << std::endl;
    f.close();
  }
  
  
  std::fstream file;
  file.open("./text.txt");
  if (file.is_open()) {
    std::string buff;
    
    do {
      std::getline(file, buff);
      std::cout << "Buff: " << buff << std::endl;
    } while(!file.eof());
    
    std::cout << "rdstate: " << file.rdstate() << std::endl;
    std::cout << "eofbit & failbit: " << (std::ifstream::eofbit | std::ifstream::failbit) << std::endl;
    
    if (file.rdstate() == (std::ifstream::eofbit | std::ifstream::failbit)) {
      std::cout << "Error: eof() and fail()" << std::endl;
    }
    file.close();
  }
  // Enum test
  auto a = Enum::CASE1;
  test(&a);
  
  return 0;
}
