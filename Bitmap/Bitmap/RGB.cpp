//
//  RGB.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "RGB.hpp"
namespace bitmap {
    RGB operator-(const RGB &rgb, const RGB &other) {
        return RGB(rgb.red - other.red, rgb.green - other.green, rgb.blue - other.blue);
    }
}
