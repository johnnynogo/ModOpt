#pragma once
#include "systemc.h"
#include "tlc.h"

SC_MODULE(tb_TLC) {
    sc_in<color> tb_main_light;
    sc_in<color> tb_side_light;
    sc_out<bool> tb_side_car_presence;

    SC_CTOR(tb_TLC) {
        SC_THREAD(tb_TLC_thread);

        SC_METHOD(tb_car_monitor);
        sensitive << tb_side_car_presence;
        dont_initialize();

        SC_METHOD(tb_light_monitor);
        sensitive << tb_main_light << tb_side_light;
        dont_initialize();
    }

    void tb_TLC_thread(void);
    void tb_car_monitor(void);
    void tb_light_monitor(void);
};