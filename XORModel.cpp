//
// Created by nesposi3 on 10/22/19.
//

#include "XORModel.h"

std::string XORModel::lambda() {
    return std::to_string(this->bit);

}

void XORModel::delta(std::vector<std::string> input) {
    int b1 = std::stoi(input[0]);
    int b2 = std::stoi(input[1]);
    this->bit = b1 ^ b2;
}

XORModel::XORModel() {
    this->bit = 0;

}
