#include "systemc.h"

#ifndef TIMER_H
    #define TIMER_H

SC_MODULE(TIMER) {
    public : 
    sc_in<bool> start;
    sc_out<bool> sec_5;

    SC_CTOR(TIMER) : start("start"), sec_5("sec_5") {
        SC_THREAD(timer);
    }

    void timer() {
        sec_5.write(false);

        while(1) {
            wait(start.posedge_event());
            wait(5, SC_SEC);
            sec_5.write(true);
            wait(start.negedge_event());
            sec_5.write(false);
        }
    }
};

#endif
