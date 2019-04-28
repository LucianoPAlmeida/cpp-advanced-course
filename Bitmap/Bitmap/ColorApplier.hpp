//
//  ColorApplier.hpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef ColorApplier_hpp
#define ColorApplier_hpp

#include <stdio.h>
#include <memory>
#include <unordered_map>
#include "Bitmap.hpp"
#include "Histogram.hpp"
#include "Coordinate.hpp"

class ColorApplier {
public:
    static void applyTo(bitmap::Bitmap &bitmap, fractal::Histogram &histogram, std::unordered_map<bitmap::Coordinate, int> iterationsMap, int maxIterations);
};
#endif /* ColorApplier_hpp */
