//
//  BitmapInfoHeader.h
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef BitmapInfoHeader_h
#define BitmapInfoHeader_h

#include <iostream>
namespace bitmap {
    
#pragma pack(2)
struct BitmapInfoHeader {
    int32_t m_header_size{40};
    int32_t m_height;
    int32_t m_width;
    int16_t m_planes{1};
    int16_t m_bitsPerPixel{24};
    int32_t m_compression{0};
    int32_t m_dataSize{0};
    int32_t m_horizontalResolution{2400};
    int32_t m_verticalResolution{2400};
    int32_t m_colors{0};
    int32_t m_importantColors{0};
};
}
#pragma pack()
#endif /* BitmapInfoHeader_h */
