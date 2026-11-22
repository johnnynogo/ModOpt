#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

// Here you must implement a module that implements all three interfaces
// and has 3 I/O signals for car, main and secondary
SC_MODULE(HW_DRIVERS), public light_if, public timer_if, public car_if {
    public : 
    sc_in<bool> car, clk;
    sc_out<color> M, S;

    SC_CTOR(HW_DRIVERS) : car("car"), clk("clk"), M("Main"), S("Sec") {}

    void set_main(color c) { M.write(c); }

    void set_sec(color c) { S.write(c); }

    void wait_for_sec(unsigned int s) {
        for (unsigned int i = 0; i < s * 1000000; i++) { wait(clk.posedge_event()); }
    }

    void wait_for_car() { while(!car.read()) { wait(clk.posedge_event()); }}

};
 
#endif
