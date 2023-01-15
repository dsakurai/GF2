cmake_minimum_required(VERSION 3.24)
project(test_eigen)

set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE True)

add_executable(test_eigen main_eigen.cpp GF2.h)

find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(test_eigen
        PUBLIC
            Eigen3::Eigen
        )

add_executable(test_cgal main_cgal.cpp GF2.h)

find_package(CGAL CONFIG REQUIRED)
target_link_libraries(test_cgal
        PUBLIC
        CGAL::CGAL
        )
