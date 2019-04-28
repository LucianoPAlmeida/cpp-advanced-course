//
//  Zoom.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "Zoom.hpp"

namespace fractal {
    void ZoomList::add(const Zoom &z) {
        zooms.push_back(z);
        m_xCenter += (z.coordinate.x - m_width/2) * m_scale;
        m_yCenter += (z.coordinate.y - m_height/2) * m_scale;
        
        m_scale*= z.scale;
    }
    
    std::pair<double, double> ZoomList::toZoom(bitmap::Coordinate c) {
        double xFractal = (c.x - m_width/2) * m_scale + m_xCenter;
        double yFractal = (c.y - m_height/2) * m_scale + m_yCenter;

        return std::pair<double, double>(xFractal, yFractal);
    }
}
