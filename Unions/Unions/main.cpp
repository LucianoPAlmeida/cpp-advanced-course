//
//  main.cpp
//  Unions
//
//  Created by Luciano Almeida on 19/04/20.
//  Copyright © 2020 Luciano Almeida. All rights reserved.
//

#include <iostream>


struct Vector2 {
  float x, y;
};

union Vector4 {
  struct {
    float x, y, z, w;
  };
  struct {
    Vector2 a, b;
  };
};

void dump(Vector2 v) {
  std::cout << "{x: "<< v.x << ", y: "<< v.y << "}" << std::endl;
}


int main(int argc, const char * argv[]) {
  // Memory area is shared.
  Vector4 v = {1.0 , 2.0 , 3.0, 4.0};
  
  dump(v.a);
  dump(v.b);
  
  v.w = 10.0;
  dump(v.a);
  dump(v.b);

  // Mutable
  
  int x = 0;
  
  auto f = [=]() mutable {
    x++;
    std::cout << "x in => " << x << std::endl;
  };
  
  f();
  
  std::cout << "x out => " << x << std::endl;

  return 0;
}
