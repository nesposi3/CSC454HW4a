//
// Created by nick on 10/16/19.
//

#ifndef CSC454HW4A_MODEL_H
#define CSC454HW4A_MODEL_H

#include <stdio.h>
#include "Pipe.h"
#include "Port.h"
#include <vector>
#include <iostream>
template <typename Input,typename Output> class Model{
    protected:
        bool debug;
        std::vector<Port<Input> *> inputPorts;
        Port<Output>* outputPort;
        std::vector<Pipe<Output> *> pipeList;
        std::vector<Model<Input,Output> *> childList;
public:
    std::string name;
    virtual Output lambda() = 0;
    virtual void delta(std::vector<Input>) = 0;
    Port<Output>* getOutputPort(){
        return this->outputPort;
    }
    std::vector<Port<Input>*> getInputPorts(){
        return this->inputPorts;
    }
    std::vector<Pipe<Output>*> getPipes(){
        return this->pipeList;
    }
    void addPort(Port<Input>* p ){
        this->inputPorts.push_back(p);
    }

    ~Model(){
        delete(this->outputPort);
        for(auto p: this->pipeList){
            delete(p);
        }
        this->pipeList.clear();
    }
    Model(){}

    void addPipe(Port<Output> *nextIn ){
        Pipe<Output>* p = new Pipe<Output>(this->outputPort,nextIn);
        this->pipeList.push_back(p);
    }
};

#endif //CSC454HW4A_MODEL_H
