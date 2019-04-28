//
//  Bitmap.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "Bitmap.hpp"
#include <iostream>
#include <fstream>

#define BYTES_PER_PIXEL 3

namespace bitmap {
    
    int Bitmap::getSize() const {
        return m_width * m_height * BYTES_PER_PIXEL;
    }
    
    Bitmap::Bitmap(int height, int width): m_height(height), m_width(width), m_pPixels(new uint8_t[getSize()]) {
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
        auto pixels = m_pPixels.get();
        auto pixelOffset = (y * BYTES_PER_PIXEL) * m_width + (x * BYTES_PER_PIXEL);
        
        pixels[pixelOffset] = blue;
        pixels[pixelOffset + 1] = green;
        pixels[pixelOffset + 2] = red;
    }
    
    bool Bitmap::writeToFile(std::string filename) {
        BitmapInfoHeader infoHeader;
        BitmapHeaderFile headerFile;
        
        headerFile.m_file_size = sizeof(BitmapHeaderFile) + sizeof(BitmapInfoHeader) + getSize();
        headerFile.m_data_offset = sizeof(BitmapHeaderFile) + sizeof(BitmapInfoHeader);
        
        infoHeader.m_height = m_height;
        infoHeader.m_width = m_width;
        
        return writeToFile(filename, infoHeader, headerFile);
    }
    
    bool Bitmap::writeToFile(std::string filename, BitmapInfoHeader infoHeader, BitmapHeaderFile headerFile) {
        std::fstream f;
        f.open(filename, std::ios::out|std::ios::binary);
        if (f.is_open()) {
            f.write(reinterpret_cast<char*>(&headerFile), sizeof(headerFile));
            f.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
            f.write(reinterpret_cast<char*>(m_pPixels.get()), getSize());
            f.close();
        }
        return false;
    }
    
    void Bitmap::forEachCoordinate(std::function<void (int, int)> fn) {
        for (int x = 0; x < m_width; ++x) {
            for (int y = 0; y < m_height; ++y) {
                fn(x, y);
            }
        }
        
    }
    
    Bitmap::~Bitmap(){}

    
}
