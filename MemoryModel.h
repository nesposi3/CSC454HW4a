//
// Created by nesposi3 on 10/22/19.
//

#ifndef CSC4544A_MEMORYMODEL_H
#define CSC4544A_MEMORYMODEL_H


#include "Model.h"
#include <iostream>
class MemoryModel: public Model<std::string,std::string> {
public:
    std::string lambda() override ;
    void delta(std::vector<std::string> input) override ;
    MemoryModel(bool debug,std::string name);
private:
    int b1;
    int b2;

};


#endif //CSC4544A_MEMORYMODEL_H
