//
// Created by Daisuke Sakurai on 2023/01/14.
//

#include "GF2.h"
#include <CGAL/Gmpq.h>
#include <CGAL/Linear_algebraCd.h>
#include <range/v3/view/enumerate.hpp>

using Quotient = CGAL::Gmpq;

template<class FT>
using Linear_algebra = CGAL::Linear_algebraCd<FT>;

int main() {

    auto print = []<class FT>(FT&&) {
        using Matrix = typename Linear_algebra<FT>::Matrix;

        auto matrix_as = [](const std::vector<std::vector<int>>& elements) {
            const int num_rows = elements.size();
            const int num_columns = elements[0].size();
            Matrix A (num_rows, num_columns);

            for (const auto& [i, row]: ranges::views::enumerate(elements)) {
                for (const auto& [j, elem]: ranges::views::enumerate(row)) {
                    A(i, j) = elem;
                }
            }
            return A;
        };

        Matrix A = matrix_as({
                                     {1, 1, 1},
                                     {1, 1, 1},
                                     {0, 0, 0},
                             });

        std::cerr << A << std::endl;
        std::cerr << "rank: " << Linear_algebra<FT>::rank(A) << std::endl;
    };

    print(Quotient{});
    print(GF2{});

    return 0;
}
