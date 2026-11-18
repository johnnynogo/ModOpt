#include "adder.h"

void Adder::adder_method(void) {
    cout << "A, B, Cin: " << A->read() << ", "<< B->read() << ", " << Cin->read() <<  " @ " << sc_time_stamp() << endl;

    Sum->write(A->read() ^ B->read() ^ Cin->read());
    Cout->write((A->read() & B->read()) ^ (Cin->read() & (A->read() ^ B->read())));
}