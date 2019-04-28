//
//  Zoom.hpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef Zoom_hpp
#define Zoom_hpp

#include <iostream>
#include <vector>
#include "Coordinate.hpp"

namespace fractal {
    struct Zoom {
        bitmap::Coordinate coordinate;
        double scale {0.0};
        
        Zoom(bitmap::Coordinate coordinate, double scale): coordinate(coordinate), scale(scale) {}
        Zoom(int x, int y, double scale): coordinate(bitmap::Coordinate(x, y)), scale(scale) {}
    };
    
    struct ZoomList {
    private:
        double m_xCenter {0};
        double m_yCenter {0};
        double m_scale {1};
        
        int m_width {0};
        int m_height {0};
        std::vector<Zoom> zooms;
    public:
        ZoomList(int width, int height): m_width(width), m_height(height) {}
        void add(const Zoom& z);
        std::pair<double, double> toZoom(bitmap::Coordinate c);
    };
}

#endif /* Zoom_hpp */
