#ifndef TLM_TLC_H
#define TLM_TLC_H

// Here you must model the TLM TLC
SC_MODULE(TLC_SW) {
    public : 
    sc_port<car_if> car;
    sc_port<timer_if> timer;
    sc_port<light_if> light;

    SC_CTOR(TLC_SW) : car("car"), timer("timer"), light("light") {
        SC_THREAD(TLC_thread);
    }

    void TLC_thread() {
        light->set_main(GREEN);
        light->set_sec(RED);

        while (1) {
            timer->wait_for_sec(10);

            car->wait_for_car();

            timer->wait_for_sec(5);

            light->set_main(YELLOW);
            timer->wait_for_sec(5);

            light->set_main(RED);
            light->set_sec(GREEN);
            timer->wait_for_sec(10);

            light->set_sec(YELLOW);
            timer->wait_for_sec(5);

            light->set_sec(RED);
            light->set_main(GREEN);
        }
    }
};

#endif
