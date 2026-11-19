#include "tlc.h"

void TLC::TLC_thread() {
    main_light->write(GREEN);
    side_light->write(RED);

    while(true) {
        main_light->write(GREEN);
        wait(10, SC_SEC);

        while (!side_car_presence.read()) {
            wait(side_car_presence.value_changed_event());
        }
        
        if (side_car_presence) {
            main_light->write(YELLOW);
            wait(5, SC_SEC);
            main_light->write(RED);
            
            side_light->write(GREEN);
            wait(10, SC_SEC);
            side_light->write(YELLOW);
            wait(5, SC_SEC);
            side_light->write(RED);
        }
    }
}
