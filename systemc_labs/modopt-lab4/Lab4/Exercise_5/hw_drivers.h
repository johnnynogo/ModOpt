#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

// This is the same as in exercise 4, but without implementing the timer
// interface
SC_MODULE(HW_DRIVERS), public light_if, public car_if {
    public : 
    sc_in<bool> car;
    sc_out<color> M, S;
    SC_CTOR(HW_DRIVERS) : car("car"), M("Main"), S("Secondary") {}

    void set_main(color c) {M.write(c);}

    void set_sec(color c) {S.write(c);}

    void wait_for_car() {if(!car.read()) {wait(car.posedge_event());}}
};

#endif
