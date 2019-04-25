//
//  Mandelbrot.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 24/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//
#include <iostream>
#include <complex>

#include "Mandelbrot.hpp"

namespace fractal {
    Mandelbrot::Mandelbrot(int maxIterations): m_maxIterations(maxIterations) {
        
    }
    
    Mandelbrot::~Mandelbrot() {}
    
    int Mandelbrot::computeIterations(double x, double y) {
        return 0;
    }
}
