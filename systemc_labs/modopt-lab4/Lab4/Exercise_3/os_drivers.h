#include <unistd.h>
#include <ctime>
#include <string>
#ifndef OS_DRIVERS_H
#define OS_DRIVERS_H

// Here you must implement a module that implements all three interfaces
SC_MODULE(OS_DRIVERS), public light_if, public timer_if, public car_if {

    SC_CTOR(OS_DRIVERS) {}
    
    void set_main(color c) {
        cout << "Main road switched to " << c << " @ " << sc_time_stamp() << endl;
    }
    
    void set_sec(color c) {
        cout << "Side road switched to " << c << " @ " << sc_time_stamp() << endl;
    }

    void wait_for_sec(unsigned int s) {
        sleep(s);
        wait(s, SC_SEC);
    }

    void wait_for_car() {
        std::string s;

        time_t start = time(NULL);
        cout << "Press ENTER to simulate that a car arrives" << endl;
        getline(cin, s);
        if (s == "STOP") { sc_stop(); }
        time_t end = time(NULL);

        wait(end - start, SC_SEC);
    }
};

#endif
