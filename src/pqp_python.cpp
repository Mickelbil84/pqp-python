#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

#include <vector>
using std::vector;

#include "PQP.h"
PQP_Model loadModel(vector<vector<double>> vertices, vector<vector<int>> faces) {
    PQP_Model model;
    PQP_REAL p1[3], p2[3], p3[3];

    model.BeginModel();
    int cnt = 0;
    for (int i = 0; i < faces.size(); i++) {
        p1[0] = vertices[faces[i][0]][0]; p1[1] = vertices[faces[i][0]][1]; p1[2] = vertices[faces[i][0]][2];
        p2[0] = vertices[faces[i][1]][0]; p2[1] = vertices[faces[i][1]][1]; p2[2] = vertices[faces[i][1]][2];
        p3[0] = vertices[faces[i][2]][0]; p3[1] = vertices[faces[i][2]][1]; p3[2] = vertices[faces[i][2]][2];
        model.AddTri(p1, p2, p3, cnt++);
    }
    model.EndModel();
    return model;
}


PYBIND11_MODULE(_pqp, m) {
    m.doc() = "Python bindings for the PQP collision detection library.";
    m.def("load_model", &loadModel, "");

    py::class_<PQP_Model>(m, "PQP_Model", "")
        .def("mem_usage", &PQP_Model::MemUsage, "");
}