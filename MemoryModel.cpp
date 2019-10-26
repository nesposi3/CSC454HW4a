//
// Created by nesposi3 on 10/22/19.
//

#include "MemoryModel.h"

std::string MemoryModel::lambda() {
    return std::to_string(this->b1);
}

void MemoryModel::delta(std::vector<std::string> input) {
    int bit = std::stoi(input[0]);
    this->b1 = this->b2;
    this->b2 = bit;
    if(this->debug){
        std::cout << this->name << " Delta. Input:  " <<bit <<  "-> State: " << "{ " << b1 <<" "<< b2 << " "<<"}" << std::endl;
    }
}

MemoryModel::MemoryModel(bool debug,std::string name) {
    this->name = name;
    this->b1 =0;
    this->b2 =0;
    this->debug = debug;
    this->pipeList = std::vector<Pipe<std::string>*>();
    this->inputPorts = std::vector<Port<std::string>*>();
    this->outputPort = new Port<std::string>();
}
