//
//  main.cpp
//  Lists
//
//  Created by Luciano Almeida on 11/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

int main(int argc, const char * argv[]) {
    
    //
    std::vector<double> n(20, 1);
    
    std::cout << "Size: " << n.size() << std::endl;
    
    auto capacity = n.capacity();
    
    std::cout << "Capacity: " << capacity << std::endl;

    for (int i = 0; i < 10000; i++) {
        if (n.capacity() != capacity) {
            capacity = n.capacity();
            std::cout << "Capacity: " << capacity << std::endl;
        }
        n.push_back(i);
    }
    
    n.resize(100);
    n.shrink_to_fit();
    
    std::cout << "Capacity: " << n.capacity() << std::endl;

    // 2D
    std::vector<std::vector<int>> grid(3, std::vector<int>(3, 0));
    for(int i=0; i< grid.size(); i++) {
        for(int j=0; j < grid[i].size(); j++) {
            grid[i][j] = i + j;
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    n.begin() + 1;
    /// List
    std::list<std::string> l;
    
    l.insert(l.begin(), "sfds");
    l.insert(l.begin(), "sfds");
    l.insert(l.begin(), "sfds");
    l.insert(++l.begin(), "second");
    l.push_back("back");
    
    std::for_each(l.begin(), l.end(), [](std::string s) { std::cout << s << std::endl;});
    
    // Multimap
    
    std::multimap<int, std::string> lookup;
    lookup.insert(std::make_pair(1, "one"));
    lookup.insert(std::make_pair(2, "dois"));
    lookup.insert(std::make_pair(2, "duo"));
    lookup.insert(std::make_pair(2, "two"));
    lookup.insert(std::make_pair(3, "three"));
    lookup.insert(std::make_pair(4, "four"));
    
    auto range = lookup.equal_range(3);
    
    for (auto i = range.first; i != range.second; ++i)
    {
        std::cout << i->first << ": " << i->second << '\n';
    }
    
    
    // Set
    std::set<int> s = {1};
    auto inserted = s.insert(1);
    if (inserted.second) {
        std::cout << *inserted.first << ": " << inserted.second << std::endl;
    }
    
    return 0;
}
