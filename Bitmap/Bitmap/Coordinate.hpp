//
//  Coordinate.hpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef Coordinate_hpp
#define Coordinate_hpp

#include <stdio.h>
#include <tuple>

namespace bitmap {
    struct Coordinate {
        int x{0};
        int y{0};
        Coordinate(int x, int y): x(x), y(y) {}
        bool operator==(const Coordinate &other) const;
    };
}

template<>
struct std::hash<bitmap::Coordinate> {
    std::size_t operator()(const bitmap::Coordinate& k) const {
        
        return std::hash<int>()(k.x) ^ std::hash<int>()(k.y);
        
    }
};

#endif /* Coordinate_hpp */
