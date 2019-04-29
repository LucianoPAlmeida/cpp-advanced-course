//
//  main.cpp
//  Templates
//
//  Created by Luciano Almeida on 24/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
class Test {
public:
    T i;
    void print() const {
        std::cout << "T: " << this->i << std::endl;
    }
};

template <class T>
void print(T t) {
    std::cout << t << std::endl;
}

void test() {
    std::cout << "Testing" << std::endl;
}

bool matches(std::string s)  {
    return s.size() != 3;
}

template <class Iterator, class T>
int count_if(Iterator begin, Iterator end, bool (*matches)(T))
{
   int count = 0;
    for (; begin != end; ++begin)
      if (matches(*begin))
        ++count;
    return count;
}


int main(int argc, const char * argv[]) {
    Test<int> t;
    t.i = 2;
    t.print();
    
    print(1);
    
    
    // Function pointers
    void (*pF)() = &test;
    void (*tpF)(int) = &print;
    std::function<void (std::string)> fn = &matches;
    
    pF();
    tpF(56);
    
    std::vector<std::string> v;
    v.push_back("two");
    v.push_back("three");
    v.push_back("one");

//    auto count = count_if(v.begin(), v.end(), matches); // Our custom count_if
    auto count = count_if(v.begin(), v.end(), matches);

    std::cout << "Count: " << count << std::endl;
    
    return 0;
}
