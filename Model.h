//
// Created by nick on 10/16/19.
//

#ifndef CSC454HW4A_MODEL_H
#define CSC454HW4A_MODEL_H

#include <stdio.h>
#include "Pipe.h"
#include "Port.h"
#include <vector>

template <typename Input,typename Output> class Model{
    protected:
        bool debug;
        std::vector<Port<Input>> inputPorts;
        std::vector<Output> outputPort;
        std::vector<Pipe<Output>> pipeList;
        std::vector<Model<Input,Output>> childList;
};

#endif //CSC454HW4A_MODEL_H
