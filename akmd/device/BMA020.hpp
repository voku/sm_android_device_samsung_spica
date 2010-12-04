#pragma once

#include <sys/time.h>

#include "device/ChipReader.hpp"
#include "Calibrator.hpp"
#include "math/Vector.hpp"

#define BMA020_NAME "/dev/bma150"

namespace akmd {

class BMA020 : public ChipReader {
    private:
    /* Open file descriptors */
    int fd;

    int index;
    Vector abuf[2];
    Vector a;

    public:
    BMA020();
    ~BMA020();

    void measure();
    Vector read();
    int get_delay();

    void start();
    void stop();
};

}
