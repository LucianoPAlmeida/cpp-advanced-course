//
//  main.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 21/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include "BitmapHeaderFile.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.hpp"

int main(int argc, const char * argv[]) {
   
    bitmap::Bitmap bm(800, 600);
    
    bm.writeToFile("bitmap_file.bmp");
    
    return 0;
}
