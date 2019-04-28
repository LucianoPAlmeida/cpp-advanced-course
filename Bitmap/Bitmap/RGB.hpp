//
//  RGB.hpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef RGB_hpp
#define RGB_hpp

#include <stdio.h>
namespace bitmap {
    struct RGB {
        u_int8_t red{0};
        u_int8_t green{0};
        u_int8_t blue{0};
        RGB() {}
        RGB(u_int8_t red, u_int8_t green, u_int8_t blue): red(red), green(green), blue(blue) {}
    };
}
#endif /* RGB_hpp */
