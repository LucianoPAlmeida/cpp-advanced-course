//
//  Bitmap.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "Bitmap.hpp"

#define BYTES_PER_PIXEL 3

namespace bitmap {
    
    int Bitmap::getSize() const {
        return m_width * m_height * BYTES_PER_PIXEL;
    }
    
    Bitmap::Bitmap(int height, int width): m_height(height), m_width(width), m_pPixels(new uint8_t[getSize()]{0}){}

    void Bitmap::setPixel(int x, int y, RGB rgb) {
        auto pixels = m_pPixels.get();
        auto pixelOffset = (y * BYTES_PER_PIXEL) * m_width + (x * BYTES_PER_PIXEL);
        
        pixels[pixelOffset] = rgb.blue;
        pixels[pixelOffset + 1] = rgb.green;
        pixels[pixelOffset + 2] = rgb.red;
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
    
    void Bitmap::forEachCoordinate(std::function<void (Coordinate)> fn) {
        for (int x = 0; x < m_width; ++x) {
            for (int y = 0; y < m_height; ++y) {
                fn(Coordinate(x, y));
            }
        }
        
    }
    
    Bitmap::~Bitmap(){}

    
}
