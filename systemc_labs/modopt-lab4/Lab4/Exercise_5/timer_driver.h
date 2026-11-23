#ifndef TIMER_DRIVER_H
#define TIMER_DRIVER_H

// Here you must implement the timer_driver, withhave a port of type bus.
SC_MODULE(TIMER_DRIVER), public timer_if {
    public :
    sc_port<bus_if> bus;

    SC_CTOR(TIMER_DRIVER) : bus("bus") {}

    void wait_for_sec(unsigned int n) {
        sc_time quantum(10, SC_MS);

        bus->write(104, n * 1000000);
        bus->write(108, 0);
        bus->write(100, 0);

        while (!bus->read(108)[2]) {wait(quantum);}
    }
};

#endif
