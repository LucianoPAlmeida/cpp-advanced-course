//
//  ColorApplier.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "ColorApplier.hpp"

void ColorApplier::applyTo(bitmap::Bitmap &bitmap, fractal::Histogram &histogram, std::unordered_map<bitmap::Coordinate, int> iterationsMap, int maxIterations) {
    bitmap::RGB startColor(10, 0, 80);
    bitmap::RGB endColor(200, 255, 100);
    bitmap::RGB colorDiff = endColor - startColor;
    
    int total = histogram.total(maxIterations);
    bitmap.forEachCoordinate([&](bitmap::Coordinate c) {
        int it = iterationsMap[c];
        if (it == maxIterations) {
            bitmap.setPixel(c.x, c.y, bitmap::RGB(255, 255, 255));
        } else {
            double hue = histogram.hue(total, it);
            uint8_t red = startColor.red + colorDiff.red * hue;
            uint8_t green = startColor.green + colorDiff.green * hue;
            uint8_t blue = startColor.blue + colorDiff.blue * hue;
            bitmap.setPixel(c.x, c.y, bitmap::RGB(red, green, blue));
        }
    });
}

