#include "systemc.h"
#include "countdown_modified.h"

int sc_main(int argc, char* argv[]) {
    CountdownModified countdown_modified_thread("countdown_modified_thread");

    std::cout << "Starting countdown from 20 to 1 with 20ns delay." << std::endl;

    sc_start();

    std::cout << "Finished countdown from 20 to 1 with 20ns delay." << std::endl;
}