#include "systemc.h"

#ifndef TIMER_CLK_H
    #define TIMER_CLK_H

SC_MODULE(TIMER_CLK) {
    public : 
    sc_in<bool> clk;
    sc_in<bool> start;
    sc_out<bool> sec_5;

    SC_CTOR(TIMER_CLK) : clk("clk"), start("start"), sec_5("sec_5") {
        SC_THREAD(timer);
        sensitive << clk.pos();
    }

    void timer() {
        sec_5.write(false);
        
        while(1) {
            while(!start.read()) { wait(); }

            for (int i = 0; i < 5000000; i++) { wait(); }
            
            sec_5.write(true);

            while(start.read()) { wait(); }

            sec_5.write(false);
        }
    }
};

#endif
