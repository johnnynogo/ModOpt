#include "tb_tlc.h"

void tb_TLC::tb_TLC_thread() {
    wait(2, SC_SEC);
    tb_side_car_presence->write(true);

    wait(3, SC_SEC);
    tb_side_car_presence->write(false);

    wait(7, SC_SEC);
    tb_side_car_presence->write(true);

    while (tb_side_light.read() != GREEN)
        wait(tb_side_light.value_changed_event());
    wait(2, SC_SEC);            
    tb_side_car_presence->write(false);

    wait(5, SC_SEC);
    tb_side_car_presence->write(true);

    wait(20, SC_SEC);
    tb_side_car_presence->write(false);
    cout << "Bad driver drove off side road " << " | " 
         << "Main: " << tb_main_light.read() << " | "
         << "Side: " << tb_side_light.read()
         << endl;
}

void tb_TLC::tb_car_monitor() {
    if (tb_side_car_presence) {
        cout << "Car has arrived on side road @ " << sc_time_stamp() << endl;
    }
    else {
        cout << "Car has left side road @ " << sc_time_stamp() << endl;
    }
}

void tb_TLC::tb_light_monitor() {
    cout << "Light changed @ " << sc_time_stamp() << " | "
         << "Main: " << tb_main_light.read() << " | "
         << "Side: " << tb_side_light.read()
         << endl;
}
