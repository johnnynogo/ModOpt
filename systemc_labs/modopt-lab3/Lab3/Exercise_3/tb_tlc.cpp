#include "tb_tlc.h"
#include <cstdlib> 

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

    cout << "---- Random traffic starts @ " << sc_time_stamp() << " ----" << endl;
    srand(42);

    for (int i = 0; i < 20; i++) {
        wait(rand() % 20 + 1, SC_SEC);
        tb_side_car_presence->write(true);

        wait(rand() % 40 + 1, SC_SEC);
        tb_side_car_presence->write(false);
    }
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

void tb_TLC::tb_red_green_monitor() {
    if (tb_main_light.read() == GREEN && tb_side_light.read() != RED) {
        cout << "Error @ " << sc_time_stamp() 
             << ": main light is indeed " << tb_main_light.read()
             << ", but side light is " << tb_side_light.read()
             << endl;
    }

    else if (tb_side_light.read() == GREEN && tb_main_light.read() != RED){
        cout << "Error @ " << sc_time_stamp() 
             << ": side light is indeed " << tb_side_light.read()
             << ", but main light is " << tb_main_light.read()
             << endl;
    }
}

void tb_TLC::tb_main_green_monitor() {
    wait(SC_ZERO_TIME);

    while(true) {
        while(tb_main_light.read() != GREEN) {
            wait(tb_main_light.value_changed_event());
        }

        sc_time start = sc_time_stamp();

        while(tb_main_light.read() == GREEN) {
            wait(tb_main_light.value_changed_event());
        }

        sc_time elapsed = sc_time_stamp() - start;

        if(elapsed < sc_time(10, SC_SEC)) {
            cout << "Error @ " << sc_time_stamp() << ". "
                 << "Main green light less than 10 s. "
                 << "Elapsed time: " << elapsed
                 << endl;
        }
    }
}

void tb_TLC::tb_side_green_monitor() {
    wait(SC_ZERO_TIME);

    while(true) {
        while(tb_side_light.read() != GREEN) {
            wait(tb_side_light.value_changed_event());
        }

        sc_time start = sc_time_stamp();

        while(tb_side_light.read() == GREEN) {
            wait(tb_side_light.value_changed_event());
        }

        sc_time elapsed = sc_time_stamp() - start;

        if(elapsed < sc_time(10, SC_SEC)) {
            cout << "Error @ " << sc_time_stamp() << ". "
                 << "Side green light less than 10 s. "
                 << "Elapsed time: " << elapsed
                 << endl;
        }
    }
}

void tb_TLC::tb_main_yellow_monitor() {
    wait(SC_ZERO_TIME);

    while (true) {
        while (tb_main_light != YELLOW) {
            wait(tb_main_light.value_changed_event());
        }

        sc_time start = sc_time_stamp();

        while (tb_main_light == YELLOW) {
            wait(tb_main_light.value_changed_event());
        }

        sc_time elapsed = sc_time_stamp() - start;

        if(elapsed > sc_time(5, SC_SEC)) {
            cout << "Error @ " << sc_time_stamp() << ". "
                 << "Main yellow light longer than 5 s. "
                 << "Elapsed time: " << elapsed
                 << endl;
        }
    }
}

void tb_TLC::tb_side_yellow_monitor() {
    wait(SC_ZERO_TIME);

    while (true) {
        while (tb_side_light != YELLOW) {
            wait(tb_side_light.value_changed_event());
        }

        sc_time start = sc_time_stamp();

        while (tb_side_light == YELLOW) {
            wait(tb_side_light.value_changed_event());
        }

        sc_time elapsed = sc_time_stamp() - start;

        if(elapsed > sc_time(5, SC_SEC)) {
            cout << "Error @ " << sc_time_stamp() << ". "
                 << "Side yellow light longer than 5 s. "
                 << "Elapsed time: " << elapsed
                 << endl;
        }
    }
}
