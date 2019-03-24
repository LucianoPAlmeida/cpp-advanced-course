//
//  ring.h
//  Section8-Cpp11
//
//  Created by Luciano Almeida on 24/03/19.
//  Copyright © 2019 Luciano Almeida. All rights reserved.
//

#ifndef ring_h
#define ring_h

#include <deque>

template <class T>
class ring {
private:
    std::deque<T> m_buffer;
    int m_size;
public:
    ring(int size): m_size(size) {}
    virtual ~ring() {}
    
    void add(T value) {
        if (m_buffer.size() < m_size) {
            m_buffer.push_back(value);
        } else {
            m_buffer.pop_back();
            m_buffer.push_front(value);
        }
    }
    
    auto size() const {
        return m_buffer.size();
    }
    
    T get(int i) const {
        return m_buffer[i];
    }

};

#endif /* ring_h */
