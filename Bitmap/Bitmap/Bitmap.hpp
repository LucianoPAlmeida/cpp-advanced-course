//
//  Bitmap.hpp
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef Bitmap_hpp
#define Bitmap_hpp

#include <stdio.h>
#include <iostream>

namespace bitmap {
class Bitmap {
private:
    int m_height{0};
    int m_width{0};
    std::unique_ptr<uint8_t[]> m_pPixels{nullptr};
public:
    Bitmap(int height, int width);
    bool writeToFile(std::string filename);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    virtual ~Bitmap();
};
}

#endif /* Bitmap_hpp */