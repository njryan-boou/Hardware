#include <thread>

#include "hardwarey/cpu.hpp"

namespace hardwarey {

unsigned int threads() {
    return std::thread::hardware_concurrency();
}

}  // namespace hardwarey
