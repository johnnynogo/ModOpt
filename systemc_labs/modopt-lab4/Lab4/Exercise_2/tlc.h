#include "systemc.h"

#ifndef TLC_H
    #define TLC_H

enum color{ RED , YELLOW , GREEN };

SC_MODULE(TLC) { 
	public :
	sc_in<bool> car;
	sc_out<color> M, S;
    sc_in<bool> sec_5;
    sc_out<bool> start;

	SC_CTOR(TLC) : car("car"), M("Main"), S("Secondary"), sec_5("sec_5"), start("start") {
		SC_THREAD(TLC_thread);
	} 

	void TLC_thread() { 
		M.write(GREEN);
		S.write(RED);   
        start.write(false);

		while (1) {
            wait_5s();
            wait_5s();      // wait(10, SC_SEC) from Ex1 replaced.

			if (!car)
			    wait(car.posedge_event()) ;

            wait_5s();

			M.write(YELLOW);
            wait_5s();      // wait (5,SC_SEC) replaced

			M.write(RED);
			S.write(GREEN);
            wait_5s();
            wait_5s();      // wait(10, SC_SEC) replaced

			S.write(YELLOW);
            wait_5s();      // wait (5,SC_SEC) replaced

			S.write(RED);
			M.write(GREEN);
		} 
	}

    void wait_5s() {
        start.write(true);
        wait(sec_5.posedge_event());
        start.write(false);
        wait(sec_5.negedge_event()); // one handshake
    }
};

#endif
