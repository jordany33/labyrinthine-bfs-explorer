#include "wavefront.h"
#include "utilities.h"
#include <ctime>

int main(int argc, char **argv) {
    srand(unsigned(time(NULL))); //random seed generator
    interface(); //print the interface
    return 0; //return 0 into main
}
