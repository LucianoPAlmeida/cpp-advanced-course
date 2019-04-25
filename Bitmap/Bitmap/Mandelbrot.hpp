//
//  Mandelbrot.hpp
//  Bitmap
//
//  Created by Luciano Almeida on 24/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp

#include <stdio.h>
namespace fractal {
    
class Mandelbrot {
private:
    int m_maxIterations;
public:
    Mandelbrot(int maxIterations);
    int computeIterations(double x, double y);
    virtual ~Mandelbrot();
};
    
}
#endif /* Mandelbrot_hpp */
