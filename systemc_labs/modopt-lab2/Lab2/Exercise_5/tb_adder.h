#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(tb_adder) {
    sc_in<bool> tb_Sum;
    sc_in<bool> tb_Cout;
    sc_out<bool> tb_A;
    sc_out<bool> tb_B;
    sc_out<bool> tb_Cin;

    SC_CTOR(tb_adder) {
        SC_THREAD(tb_adder_thread);
    }

    void tb_adder_thread(void);
};