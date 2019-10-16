//
// Created by nick on 10/16/19.
//

#ifndef CSC4543A_PORT_H
#define CSC4543A_PORT_H

#include "Pipe.h"

template<typename T>
class Port {
private:
    T t;
public:
    void setVal(T t) {
        this->t = t;
    }

    T getVal() {
        return this->t;
    }

    Port(T t) {
        this->t = t;
    }
};

#endif //CSC4543A_PORT_H
