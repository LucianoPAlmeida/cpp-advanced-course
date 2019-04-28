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
#include "Zoom.hpp"


void mandelbrot();
void desenhaUmaBolaMoiseis();

int main(int argc, const char * argv[]) {
    // Mandelbrot bitmap.
    mandelbrot();
    
    // Desenhando uma bola.
    desenhaUmaBolaMoiseis();

    return 0;
}

void mandelbrot() {
    const int WIDTH = 900;
    const int HEIGHT = 900;
    const int MAX_ITERATIONS = 1000;
    
    bitmap::Bitmap bm(HEIGHT, WIDTH);
    fractal::Mandelbrot m(MAX_ITERATIONS);
    fractal::Histogram histogram(MAX_ITERATIONS);
    std::unordered_map<bitmap::Coordinate, int> iterationsMap;
    
    fractal::ZoomList zooms(WIDTH, HEIGHT);
    zooms.add(fractal::Zoom(WIDTH/2, HEIGHT/2, 2.0/WIDTH));
    zooms.add(fractal::Zoom(200, HEIGHT - 200, 0.4));

    bm.forEachCoordinate([&](bitmap::Coordinate c) {
//        double xFractal = fractal::Mandelbrot::scaleCoordinate(c.x, WIDTH);
//        double yFractal = fractal::Mandelbrot::scaleCoordinate(c.y, HEIGHT);
        std::pair<double, double> coords = zooms.toZoom(c);
        
        int iterations = m.computeIterations(coords.first, coords.second);
//        int iterations = m.computeIterations(xFractal, yFractal);
        iterationsMap.insert(std::make_pair(bitmap::Coordinate(c.x, c.y), iterations));
        histogram.incrementValueFor(iterations);
    });
    
    ColorApplier::applyTo(bm, histogram, iterationsMap, MAX_ITERATIONS);
    
    bm.writeToFile("mandelbrot.bmp");
    
}

void desenhaUmaBolaMoiseis() {
    //  Desenha uma bola moiséis
    const int RADIUS = 300;
    bitmap::Bitmap bola(RADIUS * 2, RADIUS * 2);
    
    //  Num consegue né moiséis haha
    for (int i = 0; i < 360; ++i) {
        int y = (cos(M_PI * i /180) * RADIUS) + RADIUS;
        int x = (sin(M_PI * i /180) * RADIUS) + RADIUS;
        bola.setPixel(x, y, bitmap::RGB(255, 255, 255));
    }
    
    bola.writeToFile("desenha_uma_bola.bmp");
    
}
