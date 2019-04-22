//
//  BitmapHeaderFile.h
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef BitmapHeaderFile_h
#define BitmapHeaderFile_h

#include <iostream>

#pragma pack(2)
struct BitmapHeaderFile {
    char m_header[2]{'B', 'M'};
    int32_t m_file_size;
    int32_t m_reserved = 0;
    int32_t m_data_offset;
    
};
#pragma pack()
#endif /* BitmapHeaderFile_h */
