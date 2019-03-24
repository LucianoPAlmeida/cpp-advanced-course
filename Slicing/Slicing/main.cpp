//
//  main.cpp
//  Slicing
//
//  Created by Luciano Almeida on 24/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>

class Parent {
public:
    Parent() {}
    
    Parent(const Parent& p) {}
    
    virtual void print() {
        std::cout << "Parent" << std::endl;
    }
    
    virtual ~Parent() {}
};

class Child: public Parent {
public:
    Child() {}
    
    Child(const Child& p) {}

    void print() {
        std::cout << "Child" << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    Child c1;
    
    Parent p = c1;
    p.print();
    
    return 0;
}
