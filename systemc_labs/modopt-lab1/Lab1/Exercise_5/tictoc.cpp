#include "tictoc.h"
#include <string>

void TicToc::tic(void) {
    while(true) {
        std::cout << "Tic has woken up @ " << sc_time_stamp() << std::endl;
        TicAwakeCnt++;
        wait(10, SC_NS);
        std::cout << "Tic wakes up Toc @ " << sc_time_stamp() << std::endl;
        toc_evt.notify(SC_ZERO_TIME);
        wait(tic_evt);
    }
}

void TicToc::toc(void) {
    while(true) {
        wait(toc_evt);
        std::cout << "Toc has woken up @ " << sc_time_stamp() << std::endl;
        TocAwakeCnt++;
        wait(10, SC_NS);
        std::cout << "Toc wakes up Tic @ " << sc_time_stamp() << std::endl;
        tic_evt.notify(SC_ZERO_TIME);
    }
}