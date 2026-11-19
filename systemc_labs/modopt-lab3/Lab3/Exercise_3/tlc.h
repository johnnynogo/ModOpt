#pragma once
#include "systemc.h"

enum color {
    GREEN,
    YELLOW,
    RED
};

SC_MODULE(TLC) {
    sc_in<bool> side_car_presence;
    sc_out<color> main_light;
    sc_out<color> side_light;

    SC_CTOR(TLC) {
        SC_THREAD(TLC_thread);
    }

    void TLC_thread(void);
};