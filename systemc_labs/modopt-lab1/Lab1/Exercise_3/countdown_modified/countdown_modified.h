#include "systemc.h"

SC_MODULE(CountdownModified) {

    SC_CTOR(CountdownModified) {
        SC_THREAD(countdown_modified_thread);
    }

    void countdown_modified_thread(void);
};
