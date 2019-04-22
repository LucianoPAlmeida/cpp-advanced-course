//
//  Bitmap.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "Bitmap.hpp"
namespace bitmap {
    
    Bitmap::Bitmap(int height, int width): m_height(height), m_width(width), m_pPixels(new uint8_t[width * height * 3]) {
        
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
        
    }
    
    bool Bitmap::writeToFile(std::string filename) {
        return false;
    }
    
    Bitmap::~Bitmap(){}

    
}
