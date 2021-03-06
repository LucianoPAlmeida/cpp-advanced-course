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
#include "BitmapInfoHeader.h"
#include "BitmapHeaderFile.h"
#include "RGB.hpp"
#include "Coordinate.hpp"

namespace bitmap {
class Bitmap {
private:
    // Members
    int m_height{0};
    int m_width{0};
    std::unique_ptr<uint8_t[]> m_pPixels{nullptr};
    
    // Methods
    const int getSize() const;
    bool writeToFile(std::string filename, BitmapInfoHeader infoHeader, BitmapHeaderFile headerFile);
public:
    Bitmap(int height, int width);
    bool writeToFile(std::string filename);
    void setPixel(int x, int y, RGB rgb);
    void forEachCoordinate(std::function<void (Coordinate)> fn);
    virtual ~Bitmap();
};
}

#endif /* Bitmap_hpp */
