//
// Created by nick on 10/16/19->
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
    void delta(std::vector<Input> input) {
        this->firstChild->delta(input);
        for (Model<Input,Output>* m:this->childList) {
            std::vector<Port<Input>*> inputPorts = m->getInputPorts();
            std::vector<Input> deltaInputs = std::vector<Input>();
            for (auto* p:inputPorts) {
                deltaInputs.push_back(p->getVal());
            }
            m->delta(deltaInputs);
        }

        std::vector<Port<Input>*> inputPorts = finalChild->getInputPorts();
        std::vector<Input> deltaInputs =  std::vector<Input>();
        for (Port<Input> *p:inputPorts) {
            deltaInputs.push_back(p->getVal());
        }
        finalChild->delta(deltaInputs);

    }
    void addModel(Model<Input,Output>* m){
        this->childList.push_back(m);
    }
    Output tick(std::vector<Input> input){
        Output finalOutput;
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
        Output firstOutput = this->firstChild->lambda();
        this->firstChild->getOutputPort()->setVal(firstOutput);
        for (Pipe<Output> *p:this->firstChild->getPipes()) {
            p->shiftVal(firstOutput);
        }


        for (Model<Input,Output> *m: this->childList
                ) {
            Output output = m->lambda();
            m->getOutputPort()->setVal(output);
            for(Pipe<Output> *p: m->getPipes()){
                p->shiftVal(output);
            }
        }
        Output finalOutput = this->finalChild->lambda();
        for (Pipe<Output>* p :this->finalChild->getPipes()) {
            p->shiftVal(finalOutput);
        }
        return finalOutput;
    }
    void setFirstChild(Model<Input,Output>* m){
        this->firstChild = m;
    }
    void setFinalChild(Model<Input,Output>* m){
        this->finalChild = m;
    }

};

#endif //CSC4543A_NETWORK_H
