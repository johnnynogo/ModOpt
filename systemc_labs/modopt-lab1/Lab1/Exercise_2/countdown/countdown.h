#include "systemc.h"

SC_MODULE(Countdown){
    SC_CTOR(Countdown) {
        SC_THREAD(countdown_thread);
    }

    void countdown_thread(void);
};
