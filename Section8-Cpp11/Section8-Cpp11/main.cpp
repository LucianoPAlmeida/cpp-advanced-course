//
//  main.cpp
//  Section8-Cpp11
//
//  Created by Luciano Almeida on 24/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
template <class T, class S>
auto test(T value, S other) -> decltype(value + other) {
    return value + other;
}


int main(int argc, const char * argv[]) {
    // S08 L39 Decltype, typeid and name mangling.
    std::string s;
    std::cout << typeid(s).name() << std::endl;
    
    decltype(s) o = "da";
    std::cout << typeid(o).name() << std::endl;

    // S08 L40 The Auto keyword
    auto i = 9;
    
    std::cout << test(i, 5) << std::endl;
    
    
    return 0;
}
