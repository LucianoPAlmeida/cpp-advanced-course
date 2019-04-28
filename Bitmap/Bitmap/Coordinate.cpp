//
//  Coordinate.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "Coordinate.hpp"

namespace bitmap {
    bool Coordinate::operator==(const Coordinate &other) const {
        return std::tie(this->x, this->y) == std::tie(other.x, other.y);
    }
    
}
