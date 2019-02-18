//
//  main.cpp
//  S2L3
//
//  Created by Luciano Almeida on 17/02/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>

void throwingFunction() {
    throw "An error!";
}

int main(int argc, const char * argv[]) {
    try {
        throwingFunction();
        std::cout << "Still running\n" << std::endl;
    } catch (const char * e) {
        std::cout << e << std::endl;
    }
    return 0;
}


