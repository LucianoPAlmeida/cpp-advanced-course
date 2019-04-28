//
//  Histogram.hpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef Histogram_hpp
#define Histogram_hpp

#include <stdio.h>
#include <memory>

namespace fractal {
    
    class Histogram {
    private:
        std::unique_ptr<int[]> m_values;
        int m_size;
    public:
        Histogram(int size);
        void incrementValueFor(int iteration);
        virtual ~Histogram();
    };
};

#endif /* Histogram_hpp */
