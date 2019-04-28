//
//  main.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <memory>
#include <math.h>
#include <unordered_map>
#include "BitmapHeaderFile.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "Histogram.hpp"
#include "Coordinate.hpp"
#include "ColorApplier.hpp"

int main(int argc, const char * argv[]) {
    const int WIDTH = 2160;
    const int HEIGHT = 2160;
    const int MAX_ITERATIONS = 1000;
    
    bitmap::Bitmap bm(HEIGHT, WIDTH);
    fractal::Mandelbrot m(MAX_ITERATIONS);
    fractal::Histogram histogram(MAX_ITERATIONS);
    std::unordered_map<bitmap::Coordinate, int> iterationsMap;
    
    bm.forEachCoordinate([&](bitmap::Coordinate c) {
        double xFractal = fractal::Mandelbrot::scaleCoordinate(c.x, WIDTH);
        double yFractal = fractal::Mandelbrot::scaleCoordinate(c.y, HEIGHT);
        
        int iterations = m.computeIterations(xFractal, yFractal);
        iterationsMap.insert(std::make_pair(bitmap::Coordinate(c.x, c.y), iterations));
        histogram.incrementValueFor(iterations);
    });
    
    ColorApplier::applyTo(bm, histogram, iterationsMap, MAX_ITERATIONS);
    
    bm.writeToFile("mandelbrot.bmp");
    
//  Desenha uma bola moiséis
    const int RADIUS = 300;
    bitmap::Bitmap bola(RADIUS * 2, RADIUS * 2);

//  Num consegue né moiséis haha
    for (int i = 0; i < 360; ++i) {
        int y = (cos(M_PI * i /180) * RADIUS) + RADIUS;
        int x = (sin(M_PI * i /180) * RADIUS) + RADIUS;
        bola.setPixel(x, y, 255, 255, 255);
    }
    
    bola.writeToFile("desenha_uma_bola.bmp");
    
    return 0;
}
