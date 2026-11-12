#include "systemc.h"
#include "tictoc.h"

int sc_main(int argc, char * argv[]) {
    TicToc inst("instance");

    std::cout << "Simulation start" << std::endl;

    sc_start(100, SC_NS);

    std::cout << "Simulation finished." << std::endl;
    std::cout << "Tic activated count: " << inst.TicAwakeCnt << std::endl;
    std::cout << "Toc activated count: " << inst.TocAwakeCnt << std::endl;

    return 0;
}
