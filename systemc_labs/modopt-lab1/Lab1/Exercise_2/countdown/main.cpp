#include "systemc.h"
#include "countdown.h"

int sc_main(int argc, char* argv[]) {
    Countdown countdown_thread("countdown_thread");

    sc_start();
}