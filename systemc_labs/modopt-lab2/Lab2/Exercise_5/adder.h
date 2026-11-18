#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Adder) {
    sc_out<bool> Sum;
    sc_out<bool> Cout;
    sc_in<bool> A;
    sc_in<bool> B;
    sc_in<bool> Cin;

    SC_CTOR(Adder) {
        SC_METHOD(adder_method);
        sensitive << A << B << Cin;
    }

    void adder_method(void);
};