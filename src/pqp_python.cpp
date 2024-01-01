#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

PYBIND11_MODULE(pqp, m) {
    m.doc() = "Python bindings for the PQP collision detection library.";
}