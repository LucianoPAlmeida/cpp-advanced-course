//
//  Bitmap.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "Bitmap.hpp"
#include "BitmapInfoHeader.h"
#include "BitmapHeaderFile.h"

namespace bitmap {
    
    int Bitmap::getSize() const {
        return m_width * m_height * 3;
    }
    
    Bitmap::Bitmap(int height, int width): m_height(height), m_width(width), m_pPixels(new uint8_t[getSize()]) {
        
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
        
    }
    
    bool Bitmap::writeToFile(std::string filename) {
        BitmapInfoHeader infoHeader;
        BitmapHeaderFile headerFile;
        
        headerFile.m_file_size = sizeof(BitmapHeaderFile) + sizeof(BitmapInfoHeader) + getSize();
        headerFile.m_data_offset = sizeof(BitmapHeaderFile) + sizeof(BitmapInfoHeader);
        
        infoHeader.m_height = m_height;
        infoHeader.m_width = m_width;
        
        
        
        return false;
    }
    
    Bitmap::~Bitmap(){}

    
}
