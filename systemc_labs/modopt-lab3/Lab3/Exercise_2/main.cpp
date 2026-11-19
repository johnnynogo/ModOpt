#include <iostream>
#include "systemc.h"
#include "tlc.h"
#include "tb_tlc.h"
int sc_main(int argc, char* argv[]) {
    sc_signal<bool> sig_side_car_presence;
    sc_signal<color> sig_main_light;
    sc_signal<color> sig_side_light;

    TLC TLC_instance("TLC_Instance");
    tb_TLC tb_TLC_instance("tb_TLC_Instance");

    TLC_instance.side_car_presence(sig_side_car_presence);
    TLC_instance.main_light(sig_main_light);
    TLC_instance.side_light(sig_side_light);
    
    tb_TLC_instance.tb_side_car_presence(sig_side_car_presence);
    tb_TLC_instance.tb_main_light(sig_main_light);
    tb_TLC_instance.tb_side_light(sig_side_light);

    sc_start(70, SC_SEC);

    return 0;
}