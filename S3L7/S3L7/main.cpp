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

const Parent* get() {
    return new Child();
}


int main(int argc, const char * argv[]) {
    
    auto p1 = get();
    auto c1 = Child();
    Parent* c2 = new Child();
    
    std::cout << "p1: " << p1->name() << std::endl;
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
    return 0;
}
