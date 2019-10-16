//
// Created by nick on 10/16/19.
//

#ifndef CSC4543A_PIPE_H
#define CSC4543A_PIPE_H

#include "Port.h"

template <typename T> class Pipe{
private:
    Port<T> * previousOut;
    Port<T> * nextIn;
public:
    Pipe(Port<T> * previousOut, Port<T> * nextIn ){
        this->nextIn = nextIn;
        this->previousOut = previousOut;
    }
};

#endif //CSC4543A_PIPE_H
