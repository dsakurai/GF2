
#include "GF2.h"
#include <iostream>
#include <Eigen/Dense>

using Matrix_mod2 = Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic>;

template <class T>
T add() {
    T A (2, 2);
    T B (2, 2);

    A << 1, 0,
            0, 1;;

    B << 1, 1,
            1, 1;
    return T(A + B);
}

int main() {

    std::cerr << "Real num:\n" << add<Eigen::MatrixXd>() << std::endl;
    std::cerr << std::endl;
    std::cerr << "Z/2:\n"      << add<Matrix_mod2>() << std::endl;

    {
        Matrix_mod2 A (2, 2);
        A << 1, 1,
             1, 0;
        Eigen::FullPivLU<Matrix_mod2> lu_decomp(A);
    }

    return 0;
}
