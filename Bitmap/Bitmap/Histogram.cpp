//
//  Histogram.cpp
//  Bitmap
//
//  Created by Luciano Almeida on 28/04/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#include "Histogram.hpp"

namespace fractal {
    Histogram::Histogram(int size): m_values(new int[size]{0}), m_size(size) {}
    
    void Histogram::incrementValueFor(int iteration) {
        if (iteration < m_size)
            m_values[iteration]++;
    }
    
    Histogram::~Histogram() {}
}
