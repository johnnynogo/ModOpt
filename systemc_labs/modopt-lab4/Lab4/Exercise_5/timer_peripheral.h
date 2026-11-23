#ifndef TIMER_PERIPHERAL_H
#define TIMER_PERIPHERAL_H

// This must implement the bus interface for the timer functionality
SC_MODULE(TIMER_PERIPHERAL), public bus_if {
    public : 
    sc_in<bool> clk;
    sc_event start_ev;
    sc_int<32> counter;
    sc_int<32> max_value;
    sc_int<32> control;


    SC_CTOR(TIMER_PERIPHERAL) : clk("clk") {
        SC_THREAD(counting_thread);
    }

    void counting_thread() {
        counter = 0;
        max_value = 0;
        control = 0;
        
        while(1) {
            wait(start_ev);
            while(counter < max_value) {
                wait(clk.posedge_event()); 
                counter++;
            }
            control[2] = 1;
            counter = 0;
        }
    }

    void write(sc_int<32> addr, sc_int<32> data) {
        switch(addr) {
            case 0:
                counter = data;
                start_ev.notify(SC_ZERO_TIME);
                break;
            case 1:
                max_value = data;
                break;
            case 2:
                control = data;
                break;
            default:
                SC_REPORT_ERROR(name(), "bad address.");
                break;
        }
    }

    sc_int<32> read(sc_int<32> addr) {
        sc_int<32> temp_control;
        switch(addr) {
            case 0:
                return counter;
            case 1:
                return max_value;
            case 2:
                temp_control = control;
                control[2] = 0;
                return temp_control;
            default: 
                SC_REPORT_ERROR(name(), "bad address.");
                return 0;
        }
    }
};

#endif
