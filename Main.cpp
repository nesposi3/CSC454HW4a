//
// Created by nick on 10/16/19.
//
#include "Model.h"
#include "Port.h"
#include "Pipe.h"
#include "Network.h"
#include "iostream"
using namespace std;
int main(){
    Port<string> *p = new Port<string>("0");
    cout<<p->getVal();
    delete p;
}