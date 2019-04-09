//
//  main.cpp
//  Section8-Cpp11
//
//  Created by Luciano Almeida on 24/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include "ring.h"

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
    
    // S08 L41 Range-Based Loops
    auto texts = {"1", "3", "2"};
    
    for (auto text : texts) {
        std::cout << text << std::endl;
    }
    
    // S08 L42 Nested Template Classes
    ring<std::string> t(3);
    
    t.add("one");
    t.add("two");
    t.add("three");
    t.add("four");
    
    std::cout << "Ring" << std::endl;
    for (int i = 0; i < t.size(); i++) {
        std::cout << t.get(i) << std::endl;
    }
    
    // Anonymous struct
    struct {
        int i;
        std::string s;
    } s1 {1, ""};
    
    std::cout << s1.i << std::endl;
    
    
    //Lambdas
    
    auto l = [](std::string s) { std::cout << "Inside: " << s << std::endl; };
    l("dsad");
    
    auto l1 = [](decltype(i) s) { std::cout << "Inside template: " << s << std::endl; };
    l1(1);
    
    std::string str;
    
//  [=, &i] the default is value and i is by ref.
//  [&, i]  the default is ref and i is by value.
    
    auto l2 = [&]() { // all captured by reference
        i = 1000;
        std::cout << "Inside template: " << i << std::endl;
    };
    
    l2();
    
    std::cout << "I: " << i << std::endl;

    return 0;
}
