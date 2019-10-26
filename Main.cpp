//
// Created by nick on 10/16/19.
//
#include "Model.h"
#include "Port.h"
#include "Pipe.h"
#include "Network.h"
#include "iostream"
#include "MemoryModel.h"
#include "XORModel.h"

#define atomicTicks 3
using namespace std;
int main(int argc, char *argv[]){
    bool debug = false;
    bool batch = false;
    bool inject = false;
    for (int i = 1; i <argc ; ++i) {
        std::string arg = std::string(argv[i]);
        if(arg.find("-b")!=std::string::npos || arg.find("--batch")!=std::string::npos){
            batch = true;
        }
        if(arg.find("-d")!=std::string::npos || arg.find("--debug")!=std::string::npos){
            debug = true;
        }if(arg.find("-i")!=std::string::npos || arg.find("--inject")!=std::string::npos){
            inject = true;
        }
    }
    int numTicks = atomicTicks;
    if(inject){
        numTicks = 1;
    }
    std::string command;
    Network<std::string,std::string> *network = new Network<std::string,std::string>(numTicks,debug);
    MemoryModel* memoryModel = new MemoryModel(debug,"Memory");
    XORModel* xor1 = new XORModel(debug,"XOR1");
    XORModel* xor2 = new XORModel(debug,"XOR2");
    Port<string> *memP1 = new Port<string>("0");
    Port<string> *xor2P1 = new Port<string>("0");
    Port<string> *xor2P2 = new Port<string>("0");
    xor1->addPipe(xor2P1);
    xor2->addPort(xor2P1);
    xor2->addPort(xor2P2);
    xor2->addPipe(memP1);
    memoryModel->addPort(memP1);
    memoryModel->addPipe(xor2P2);
    network->setFirstChild(xor1);
    network->setFinalChild(xor2);
    network->addModel(memoryModel);
    if(batch){
        getline(cin,command);
        if(command.length()%2 != 0){
            cout<<"Incorrect trajectory format, uneven number of bits" <<std::endl;
        }else{
            for (int i = 0; i <command.length() ; i+=2) {
                std::string b1 = command.substr(i,i+1);
                std::string b2 = command.substr(i+1,i+2);
                vector<std::string> input =  vector<std::string>();
                input.push_back(b1);
                input.push_back(b2);
                std::string out = network->tick(input);
                cout <<out <<std::endl;
            }
            //cleanup
            delete memP1;
            delete xor2P1;
            delete xor2P2;
            delete memoryModel;
            delete xor1;
            delete xor2;
            delete network;
        }
    }else{
        while(true){
            std::string b1;
            std::string b2;
            cin>>b1;
            if(b1=="exit"){
                //cleanup
                delete memP1;
                delete xor2P1;
                delete xor2P2;
                delete memoryModel;
                delete xor1;
                delete xor2;
                delete network;
                break;
            }
            cin>>b2;
            vector<std::string> input =  vector<std::string>();
            input.push_back(b1);
            input.push_back(b2);
            std::string out = network->tick(input);
            cout <<out <<std::endl;
        }

    }

}