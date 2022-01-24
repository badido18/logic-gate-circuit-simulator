#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include <bits/stdc++.h>

#include "Gate.hpp"
#include "Utils.hpp"
#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "LogicGate.hpp"
#include "TwoArgGate.hpp"
#include "OneArgGate.hpp"

using namespace std;

int main()
{
    Utils::Demo();

    //  Exemple de sujet
    InputGate *a = new InputGate("a");
    InputGate *b = new InputGate("b");
    InputGate *d = new InputGate("d");

    Gate *or1 = new NeGate(a);
    Gate *or2 = new OrGate(or1, b);
    Gate *nand = new NandGate(or2, d);
    Gate *and1 = new AndGate(a, b);
    Gate *and2 = new XorGate(or2, and1);
    OutputGate *A = new OutputGate(nand, "A");
    a->setValue(true);
    b->setValue(true);
    d->setValue(false);
    // A->calculate();
    string text = Utils::GateToText(A);
    // printw(text.data());
    // printw(Utils::GateToText(Utils::TextToGate(text)).data());
    // Utils::Draw(A, INITIAL_Y, INITIAL_X);
    // Utils::Simulation(A, INITIAL_Y, INITIAL_X);
    // clear cache of input Instances
    Utils::inputGates.clear();

    A->reset();

    // Mon exemple
    // InputGate a("a");
    // InputGate b("b");
    // a.setValue(true);
    // b.setValue(false);
    // OrGate orgate(&a,&b);
    // OutputGate Aout( &orgate );
    // cout << GateToText(Aout) << endl ;
    // cout << Aout.calculate() << endl ;

    return 0;
}