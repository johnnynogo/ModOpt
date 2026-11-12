#include "countdown_modified.h"

void Countdown::countdown_thread(void) {
    for(int i = 3; i > 0; i--) {
        std::cout << i << std::endl;
    }
}
