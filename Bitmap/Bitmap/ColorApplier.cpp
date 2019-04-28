//
//  ColorApplier.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "ColorApplier.hpp"

void ColorApplier::applyTo(bitmap::Bitmap &bitmap, fractal::Histogram &histogram, std::unordered_map<bitmap::Coordinate, int> iterationsMap, int maxIterations) {
    int total = histogram.total(maxIterations);
    bitmap.forEachCoordinate([&](bitmap::Coordinate c) {
        int it = iterationsMap[c];
        if (it == maxIterations) {
            bitmap.setPixel(c.x, c.y, bitmap::RGB());
        } else {
            double hue = histogram.hue(total, it);
            bitmap.setPixel(c.x, c.y, bitmap::RGB(0, pow(255, hue), 0));
        }
    });
}

