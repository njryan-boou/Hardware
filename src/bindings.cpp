#include <pybind11/pybind11.h>

#include "hardwarey/cpu.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_core, module) {
    module.doc() = "Python bindings for hardwarey";

    module.def("threads", &hardwarey::threads, "Get the number of threads available on the CPU");
}
