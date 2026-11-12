#include "countdown_modified.h"

void CountdownModified::countdown_modified_thread(void) {
    const sc_time t_20NS(20, SC_NS);

    for(int i = 20; i > 0; i--) {
        std::cout << "Time is " << sc_time_stamp() << " | Countdown " << i << std::endl;
        // std::cout << "Delaying " << t_20NS << "\n" << std::endl;
        
        if (i > 1) {
            wait(t_20NS);
        }

    }
}
