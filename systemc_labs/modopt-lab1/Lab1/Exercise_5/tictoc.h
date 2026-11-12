#include "systemc.h"
#include <string>

SC_MODULE(TicToc) {
    sc_event tic_evt, toc_evt;

    int TicAwakeCnt = 0;
    int TocAwakeCnt = 0;

    SC_CTOR(TicToc) {
        SC_THREAD(tic);
        SC_THREAD(toc);
    }

    void tic();
    void toc();
};
