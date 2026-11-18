#include "systemc.h"
#include "adder.h"
#include "tb_adder.h"

int sc_main(int argc, char * argv[]) {
    sc_signal<bool> sig_A;
    sc_signal<bool> sig_B;
    sc_signal<bool> sig_Cin;
    sc_signal<bool> sig_Cout;
    sc_signal<bool> sig_Sum;

    Adder    Adder_instance("Adder_Instance");
    tb_adder tb_Adder_instance("Testbench_Adder_Instance");

    Adder_instance.A(sig_A);
    Adder_instance.B(sig_B);
    Adder_instance.Cin(sig_Cin);
    Adder_instance.Sum(sig_Sum);
    Adder_instance.Cout(sig_Cout);

    tb_Adder_instance.tb_A(sig_A);
    tb_Adder_instance.tb_B(sig_B);
    tb_Adder_instance.tb_Cin(sig_Cin);
    tb_Adder_instance.tb_Sum(sig_Sum);
    tb_Adder_instance.tb_Cout(sig_Cout);

    sc_start();

    return 0;
}