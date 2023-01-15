
#include "GF2.h"

#include <Eigen/Core>
namespace Eigen {
    template <>
    struct NumTraits<GF2> : NumTraits<int> {
        // https://eigen.tuxfamily.org/dox/structEigen_1_1NumTraits.html
        enum {
            IsComplex = 0,
            IsInteger = 1, // This likely indicates that the class is not a field. In this case it is a field, so it might work even if set to 0...
            IsSigned = 0,
            RequireInitialization = 1,
            ReadCost = 1,
            AddCost = 3,
            MulCost = 3
        };
    };
}  // namespace Eigen

bool isfinite(const GF2 &) { return true; }

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
        // can be used if IsInteger is set to 0, but I'm not sure if it gives the correct answer.
//        Eigen::FullPivLU<Matrix_mod2> lu_decomp(A);
    }

    return 0;
}
