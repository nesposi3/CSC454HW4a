//
// Created by nesposi3 on 10/22/19.
//

#ifndef CSC454HW4A_XORMODEL_H
#define CSC454HW4A_XORMODEL_H

#include "Model.h"
#include <iostream>
class XORModel:Model<std::string,std::string> {
public:
    std::string lambda() override;
    void delta(std::vector<std::string>) override;
    XORModel();

private:
    int bit;

};


#endif //CSC454HW4A_XORMODEL_H
