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

int main(int argc, const char * argv[]) {
//    const int WIDTH = 600;
//    const int HEIGHT = 600;
    const int RADIUS = 300;

    bitmap::Bitmap bm(RADIUS * 2, RADIUS * 2);
    
//  Desenha uma bola... num consegue né moiséis 
    for (int i = 0; i < 360; ++i) {
        int y = (cos(M_PI * i /180) * RADIUS) + RADIUS;
        int x = (sin(M_PI * i /180) * RADIUS) + RADIUS;
        bm.setPixel(x, y, 255, 255, 255);
    }
    
    bm.writeToFile("bitmap_file.bmp");
    
    return 0;
}
