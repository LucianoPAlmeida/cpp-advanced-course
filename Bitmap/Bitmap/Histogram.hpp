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
        int& operator[] (const int index);
        void incrementValueFor(int iteration);
        int total(int maxIterations) const;
        double hue(int total, int interations) const;
        virtual ~Histogram();
    };
};

#endif /* Histogram_hpp */
