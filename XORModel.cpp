//
// Created by nesposi3 on 10/22/19.
//

#include "XORModel.h"

std::string XORModel::lambda() {
    if(this->debug){
        std::cout << this->name << " Lambda: "<< this->bit<< std::endl;
    }
    return std::to_string(this->bit);

}

void XORModel::delta(std::vector<std::string> input) {
    int b1 = std::stoi(input[0]);
    int b2 = std::stoi(input[1]);
    this->bit = b1 ^ b2;
    if(this->debug){
        std::cout << this->name << " Delta: "<< b1 << "^" << b2 << "=" << this->bit<< std::endl;
    }
}

XORModel::XORModel(std::string name) {
    this->bit = 0;
    this->name = name;
    this->pipeList = std::vector<Pipe<std::string>*>();
    this->inputPorts = std::vector<Port<std::string>*>();
    this->outputPort = new Port<std::string>();
}

XORModel::~XORModel() {
    delete this->outputPort;

}
