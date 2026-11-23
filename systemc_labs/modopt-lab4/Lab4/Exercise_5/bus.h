#ifndef BUS_H
#define BUS_H

// This must implement the bus interface and have a port of type bus called 
// timer.
SC_MODULE(BUS), public bus_if {
    public :
    sc_port<bus_if> timer;

    SC_CTOR(BUS) : timer("timer") {}

    void write(sc_int<32> addr, sc_int<32> data) {
        switch(addr) {
            case 100:
                timer->write(0, data);
                break;
            case 104:
                timer->write(1, data);
                break;
            case 108:
                timer->write(2, data);
                break;
            default:
                SC_REPORT_ERROR(name(), "bad address.");
                break;
        }
    }
    
    sc_int<32> read(sc_int<32> addr) {
        switch(addr) {
            case 100:
                return timer->read(0);
            case 104:
                return timer->read(1);
            case 108:
                return timer->read(2);
            default:
                SC_REPORT_ERROR(name(), "bad address.");
                return 0;
        }
    }
};

#endif
