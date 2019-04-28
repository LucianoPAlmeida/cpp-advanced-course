//
//  Zoom.hpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef Zoom_hpp
#define Zoom_hpp

#include <stdio.h>
#include "Coordinate.hpp"

namespace bitmap {
    struct Zoom {
        Coordinate coordinate;
        double scale {0.0};
        
        Zoom(Coordinate coordinate, double scale): coordinate(coordinate), scale(scale) {}
        Zoom(int x, int y, double scale): coordinate(Coordinate(x, y)), scale(scale) {}
    };
}

#endif /* Zoom_hpp */
