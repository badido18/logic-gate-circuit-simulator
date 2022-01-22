#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include "Gate.hpp"
#include "Utils.hpp"
#include "OutputGate.hpp"

using namespace std;

OutputGate::OutputGate(Gate* gate1p):Gate(4){
    gate = gate1p ;
}
        
bool OutputGate::calculate(){
    return gate->calculate() ;
}

void OutputGate::update(){
    value = gate->getValue() ;
}

void OutputGate::simulate(){
    gate->update();
    gate->simulate();
    //DrawSimulation(this);
}

void OutputGate::reset(){
    value = 0 ;
    gate->reset();
}

Gate* OutputGate::getGate(){
    return gate ;
}
Gate* OutputGate::getGate1() {
    return this ;
};
Gate* OutputGate::getGate2() {
    return this ;
} ;