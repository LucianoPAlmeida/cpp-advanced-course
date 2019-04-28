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
    
    int& Histogram::operator[] (const int index) {
        return m_values[index];
    }
    
    int Histogram::total(int maxIterations) const {
        int total = 0;
        for (int i = 0; i < maxIterations; i++) {
            total+= m_values[i];
        }
        return total;
    }
    
    double Histogram::hue(int total, int interations) const {
        double hue = 0;
        for (int i = 0; i < interations; i++) {
            hue+= ((double)m_values[i])/total;
        }
        return hue;
    }
    
    Histogram::~Histogram() {}
}
