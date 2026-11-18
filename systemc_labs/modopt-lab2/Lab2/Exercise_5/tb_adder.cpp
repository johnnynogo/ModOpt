#include "tb_adder.h"

void tb_adder::tb_adder_thread(void) {

    // Combination 1: 000
    tb_A->write(false);
    tb_B->write(false);
    tb_Cin->write(false);

    wait(1, SC_NS);

    cout << "A=" << tb_A->read() << " B=" << tb_B->read() << " Cin=" << tb_Cin->read()
         << "  ->  Sum=" << tb_Sum->read() << " Cout=" << tb_Cout->read()
         << " @ " << sc_time_stamp() << endl;

    wait(1, SC_NS);

    // Combination 2: 001
    tb_A->write(false);
    tb_B->write(false);
    tb_Cin->write(true);

    wait(1, SC_NS);

    cout << "A=" << tb_A->read() << " B=" << tb_B->read() << " Cin=" << tb_Cin->read()
         << "  ->  Sum=" << tb_Sum->read() << " Cout=" << tb_Cout->read()
         << " @ " << sc_time_stamp() << endl;

    wait(1, SC_NS);

        // Combination 3: 010
    tb_A->write(false);
    tb_B->write(true);
    tb_Cin->write(false);

    wait(1, SC_NS);

    cout << "A=" << tb_A->read() << " B=" << tb_B->read() << " Cin=" << tb_Cin->read()
         << "  ->  Sum=" << tb_Sum->read() << " Cout=" << tb_Cout->read()
         << " @ " << sc_time_stamp() << endl;

    wait(1, SC_NS);

    // Combination 4: 011
    tb_A->write(false);
    tb_B->write(true);
    tb_Cin->write(true);

    wait(1, SC_NS);

    cout << "A=" << tb_A->read() << " B=" << tb_B->read() << " Cin=" << tb_Cin->read()
         << "  ->  Sum=" << tb_Sum->read() << " Cout=" << tb_Cout->read()
         << " @ " << sc_time_stamp() << endl;

    wait(1, SC_NS);

    // Combination 5: 100
    tb_A->write(true);
    tb_B->write(false);
    tb_Cin->write(false);

    wait(1, SC_NS);

    cout << "A=" << tb_A->read() << " B=" << tb_B->read() << " Cin=" << tb_Cin->read()
         << "  ->  Sum=" << tb_Sum->read() << " Cout=" << tb_Cout->read()
         << " @ " << sc_time_stamp() << endl;

    wait(1, SC_NS);

    // Combination 6: 101
    tb_A->write(true);
    tb_B->write(false);
    tb_Cin->write(true);

    wait(1, SC_NS);

    cout << "A=" << tb_A->read() << " B=" << tb_B->read() << " Cin=" << tb_Cin->read()
         << "  ->  Sum=" << tb_Sum->read() << " Cout=" << tb_Cout->read()
         << " @ " << sc_time_stamp() << endl;

    wait(1, SC_NS);

    // Combination 7: 110
    tb_A->write(true);
    tb_B->write(true);
    tb_Cin->write(false);

    wait(1, SC_NS);

    cout << "A=" << tb_A->read() << " B=" << tb_B->read() << " Cin=" << tb_Cin->read()
         << "  ->  Sum=" << tb_Sum->read() << " Cout=" << tb_Cout->read()
         << " @ " << sc_time_stamp() << endl;

    wait(1, SC_NS);

    // Combination 8: 111
    tb_A->write(true);
    tb_B->write(true);
    tb_Cin->write(true);

    wait(1, SC_NS);

    cout << "A=" << tb_A->read() << " B=" << tb_B->read() << " Cin=" << tb_Cin->read()
         << "  ->  Sum=" << tb_Sum->read() << " Cout=" << tb_Cout->read()
         << " @ " << sc_time_stamp() << endl;

    wait(1, SC_NS);

}