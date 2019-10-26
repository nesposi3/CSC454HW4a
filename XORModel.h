//
// Created by nesposi3 on 10/22/19.
//

#ifndef CSC454HW4A_XORMODEL_H
#define CSC454HW4A_XORMODEL_H

#include "Model.h"
#include <iostream>
class XORModel: public Model<std::string,std::string> {
public:
    std::string lambda() override;
    void delta(std::vector<std::string>) override;
    XORModel(bool debug,std::string name);

private:
    int bit;

};


#endif //CSC454HW4A_XORMODEL_H
