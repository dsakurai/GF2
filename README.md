# GF2
Modulo 2 (aka GF2) arithmetics for matrix computation that can be used in CGAL and Eigen.
The implementation is experimental and is not well tested.

CGAL has a good chance of correctness since its linear algebra package is tested with quotient numbers for doing exact computation.

Eigen apparently focuses on non-exact computation, so some computations (like computing the square root with Eigen's built-in function) might not work.
By setting NumTraits<int>::IsInteger to 1 (i.e. true) the correctness can be guaranteed.
However, this also prohibits you from using most rank computation algorithms if not all of them.

If you know some Eigen algorithms that disallow integer types only because it requires division (i.e. a field), you can set the enum value to 0 (i.e. false) and the algorithm works fine.
