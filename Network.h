//
// Created by nick on 10/16/19.
//

#ifndef CSC4543A_NETWORK_H
#define CSC4543A_NETWORK_H

#include "Model.h"
#include "iostream"
template <typename Input,typename Output> class Network: Model<Input,Output>{
private:
    int numTicks;
    Model<Input,Output> *firstChild;
    Model<Input,Output> * finalChild;
public:
    Network(int numTicks,bool debugFlag){
        this->numTicks = numTicks;
        this->debug = debugFlag;
    }
    void delta(std::vector<Input> input){

    }
    void addModel(Model<Input,Output> m){
        this->childList.push_back(m);
    }
    Output tick(std::vector<Input> input){
        Output finalOutput = NULL;
        for (int i = 0; i <numTicks ; i++) {
            finalOutput = lambda();
            delta(input);
            if (this->debug){
                std::cout<<"-------------"<<std::endl;
            }
        }
        return finalOutput;
    }
    Output lambda() {
        Output firstOutput = this->firstChild.lambda();
        this->firstChild->getOutputPort()->setVal(firstOutput);
        for (auto this->firstChild->getPipes() :this.firstChild.getPipes()
                ) {
            p.shiftVal(firstOutput);
        }


        for (Model<Input,Output> m: this.childList
                ) {
            Output output = m.lambda();
            m.getOutputPort().setVal(output);
            for(Pipe<Output> p: m.getPipes()){
                p.shiftVal(output);
            }
        }
        Output finalOutput = this.finalChild.lambda();
        for (Pipe<Output> p :this.finalChild.getPipes()) {
            p.shiftVal(finalOutput);

        }
        return finalOutput;
    }

};

#endif //CSC4543A_NETWORK_H
