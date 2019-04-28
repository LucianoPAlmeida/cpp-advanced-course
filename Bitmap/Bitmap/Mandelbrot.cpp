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
    
    int Mandelbrot::computeIterations(double xf, double yf) {
        int iterations = 0;
        std::complex<double> c(xf, yf);
        std::complex<double> z(0, 0);
        while (abs(z) < 2 && iterations < m_maxIterations) {
            z = z * z + c;
            iterations++;
        }
        return iterations;
    }
}
