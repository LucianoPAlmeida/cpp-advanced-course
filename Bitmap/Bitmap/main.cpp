//
//  main.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "BitmapHeaderFile.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"

int main(int argc, const char * argv[]) {
    const int WIDTH = 3840;
    const int HEIGHT = 2160;
    
    bitmap::Bitmap bm(HEIGHT, WIDTH);
    fractal::Mandelbrot m(1000);
    
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            double xFractal = (x - WIDTH/2.0) * (4.0/WIDTH);
            double yFractal = (y - HEIGHT/2.0) * (4.0/HEIGHT);
            
            int iterations = m.computeIterations(xFractal, yFractal);
            bm.setPixel(x,y, (iterations >> 16) & 255, (iterations >> 8) & 255, iterations & 255);
            
        }
    }
    
    bm.writeToFile("mandelbrot.bmp");
    
//  Desenha uma bola moiséis
    const int RADIUS = 300;
    bitmap::Bitmap bola(RADIUS, RADIUS);

//  Num consegue né moiséis haha
    for (int i = 0; i < 360; ++i) {
        int y = (cos(M_PI * i /180) * RADIUS) + RADIUS;
        int x = (sin(M_PI * i /180) * RADIUS) + RADIUS;
        bola.setPixel(x, y, 255, 255, 255);
    }
    
    bola.writeToFile("desenha_uma_bola.bmp");
    
    return 0;
}
