#include "utilities.h"
#include <cstdlib>

// Implementation for utility functions
float frand() {
    return (float)(rand() % RAND_MAX) / (float)RAND_MAX;
}
