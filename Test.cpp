#include "doctest.h"
#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE("Test RealVariable")
{
    RealVariable x;
    CHECK(solve(2 * x - 4 == 10) == double(7));
    CHECK(solve(x + x - 4 == 10) == double(7));
    CHECK(solve(x / 2 - 4 == 10) == double(28));
    CHECK(solve(x / 2 - 4 == 10) == double(28.0));
    CHECK(solve((x ^ 2) - 10 * x + 25 == 0) == double(5));
    CHECK(solve((x ^ 2) - 6 * x + 9 == 0) == double(3));
    CHECK(solve((x ^ 2) - 4 * x + 4 == 0) == double(2));
    CHECK(solve((x ^ 2) - 2 * x + 1 == 0) == double(1));
    CHECK(solve((x ^ 2) - 14 * x + 49 == 0) == double(7));
    CHECK(solve((x ^ 2) - 20 * x + 100 == 0) == double(10));
    CHECK(solve((x ^ 2) - 12 * x + 36 == 0) == double(6));
    CHECK(solve((x ^ 2) - 8 * x + 16 == 0) == double(4));
    CHECK(solve((x ^ 2) - 18 * x + 81 == 0) == double(9));
    CHECK((solve((x ^ 2) - 5 * x + 6 == 0) == double(3) || solve((x ^ 2) - 5 * x + 6 == 0) == double(2)));
    CHECK((solve((x ^ 2) - 4 * x + 3 == 0) == double(3) || solve((x ^ 2) - 4 * x + 3 == 0) == double(1)));
    CHECK((solve((x ^ 2) - 7 * x + 6 == 0) == double(6) || solve((x ^ 2) - 7 * x + 6 == 0) == double(1)));
    CHECK((solve((x ^ 2) - 8 * x + 7 == 0) == double(7) || solve((x ^ 2) - 8 * x + 7 == 0) == double(1)));
    CHECK((solve((x ^ 2) - 9 * x + 8 == 0) == double(8) || solve((x ^ 2) - 9 * x + 8 == 0) == double(1)));
    CHECK(solve(-1 * x == 0) == double(0));
    CHECK((solve((x ^ 2) == 1) == double(1) || solve((x ^ 2) == 100) == double(-1)));
    CHECK((solve((x ^ 2) == 4) == double(2) || solve((x ^ 2) == 100) == double(-2)));
    CHECK((solve((x ^ 2) == 16) == double(4) || solve((x ^ 2) == 16) == double(-4)));
    CHECK((solve((x ^ 2) == 9) == double(3) || solve((x ^ 2) == 9) == double(-3)));
    CHECK((solve((x ^ 2) == 25) == double(5) || solve((x ^ 2) == 25) == double(-5)));
    CHECK((solve((x ^ 2) == 100) == double(10) || solve((x ^ 2) == 100) == double(-10)));
    CHECK((solve((x ^ 2) == 49) == double(7) || solve((x ^ 2) == 100) == double(-7)));
    CHECK((solve((x ^ 2) == 36) == double(6) || solve((x ^ 2) == 100) == double(-6)));
    CHECK((solve((x ^ 2) == 81) == double(9) || solve((x ^ 2) == 100) == double(-9)));
    CHECK(solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == double(4));
    CHECK(solve(2 * x - 4.0 == 10) == double(7.0));
    CHECK(solve((x ^ 2) + 4 * x + 4 == 0) == double(-2));
    CHECK(solve((x ^ 2) + 8 * x + 16 == 0) == double(-4));
    CHECK(solve((x ^ 2) + 6 * x + 9 == 0) == double(-3));
    CHECK(solve((x ^ 2) + 10 * x + 25 == 0) == double(-5));
    CHECK(solve((x ^ 2) + 12 * x + 36 == 0) == double(-6));
    CHECK(solve((x ^ 2) + 14 * x + 49 == 0) == double(-7));
    CHECK(solve((x ^ 2) + 16 * x + 64 == 0) == double(-8));
    CHECK(solve((x ^ 2) + 18 * x + 81 == 0) == double(-9));
    CHECK(solve((x ^ 2) + 20 * x + 100 == 0) == double(-10));
    CHECK_THROWS_AS(solve((x ^ 2) == -16), std::exception);
    CHECK_THROWS_AS(solve(9 * (x ^ 2) + 8 * x + 7 == 0), std::exception);
    CHECK_THROWS_AS(solve(3 * (x ^ 2) + 4 * x + 5 == 0), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) + 2 * x + 3 == 0), std::exception);
    CHECK_THROWS_AS(solve(5 * (x ^ 2) + 6 * x + 7 == 0), std::exception);
    CHECK_THROWS_AS(solve(2 * (x ^ 2) + 3 * x + 4 == 0), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -49), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -1), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -16), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -25), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -9), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -36), std::exception);
    CHECK_THROWS_AS(solve((x ^ 2) == -100), std::exception);
};

TEST_CASE("Test ComplexVariable")
{
    ComplexVariable x;
    CHECK(solve(2 * x - 4 == 10) == double(7));
    CHECK(solve(x + x - 4 == 10) == double(7));
    CHECK(solve(x / 2 - 4 == 10) == double(28));
    CHECK(solve(x / 2 - 4 == 10) == double(28.0));
    CHECK(solve((x ^ 2) - 10 * x + 25 == 0) == double(5));
    CHECK(solve((x ^ 2) - 6 * x + 9 == 0) == double(3));
    CHECK(solve((x ^ 2) - 4 * x + 4 == 0) == double(2));
    CHECK(solve((x ^ 2) - 2 * x + 1 == 0) == double(1));
    CHECK(solve((x ^ 2) - 14 * x + 49 == 0) == double(7));
    CHECK(solve((x ^ 2) - 20 * x + 100 == 0) == double(10));
    CHECK(solve((x ^ 2) - 12 * x + 36 == 0) == double(6));
    CHECK(solve((x ^ 2) - 8 * x + 16 == 0) == double(4));
    CHECK(solve((x ^ 2) - 18 * x + 81 == 0) == double(9));
    CHECK((solve((x ^ 2) - 5 * x + 6 == 0) == double(3) || solve((x ^ 2) - 5 * x + 6 == 0) == double(2)));
    CHECK((solve((x ^ 2) - 4 * x + 3 == 0) == double(3) || solve((x ^ 2) - 4 * x + 3 == 0) == double(1)));
    CHECK((solve((x ^ 2) - 7 * x + 6 == 0) == double(6) || solve((x ^ 2) - 7 * x + 6 == 0) == double(1)));
    CHECK((solve((x ^ 2) - 8 * x + 7 == 0) == double(7) || solve((x ^ 2) - 8 * x + 7 == 0) == double(1)));
    CHECK((solve((x ^ 2) - 9 * x + 8 == 0) == double(8) || solve((x ^ 2) - 9 * x + 8 == 0) == double(1)));
    CHECK(solve(-1 * x == 0) == double(0));
    CHECK((solve((x ^ 2) == 1) == double(1) || solve((x ^ 2) == 100) == double(-1)));
    CHECK((solve((x ^ 2) == 4) == double(2) || solve((x ^ 2) == 100) == double(-2)));
    CHECK((solve((x ^ 2) == 16) == double(4) || solve((x ^ 2) == 16) == double(-4)));
    CHECK((solve((x ^ 2) == 9) == double(3) || solve((x ^ 2) == 9) == double(-3)));
    CHECK((solve((x ^ 2) == 25) == double(5) || solve((x ^ 2) == 25) == double(-5)));
    CHECK((solve((x ^ 2) == 100) == double(10) || solve((x ^ 2) == 100) == double(-10)));
    CHECK((solve((x ^ 2) == 49) == double(7) || solve((x ^ 2) == 100) == double(-7)));
    CHECK((solve((x ^ 2) == 36) == double(6) || solve((x ^ 2) == 100) == double(-6)));
    CHECK((solve((x ^ 2) == 81) == double(9) || solve((x ^ 2) == 100) == double(-9)));
    CHECK(solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == double(4));
    CHECK(solve(2 * x - 4.0 == 10) == double(7.0));
    CHECK(solve((x ^ 2) + 4 * x + 4 == 0) == double(-2));
    CHECK(solve((x ^ 2) + 8 * x + 16 == 0) == double(-4));
    CHECK(solve((x ^ 2) + 6 * x + 9 == 0) == double(-3));
    CHECK(solve((x ^ 2) + 10 * x + 25 == 0) == double(-5));
    CHECK(solve((x ^ 2) + 12 * x + 36 == 0) == double(-6));
    CHECK(solve((x ^ 2) + 14 * x + 49 == 0) == double(-7));
    CHECK(solve((x ^ 2) + 16 * x + 64 == 0) == double(-8));
    CHECK(solve((x ^ 2) + 18 * x + 81 == 0) == double(-9));
    CHECK(solve((x ^ 2) + 20 * x + 100 == 0) == double(-10));
    CHECK((solve((x ^ 2) == -16) == std::complex<double>(0, 4) || solve((x ^ 2) == -16) == std::complex<double>(0, -4)));
    CHECK((solve((x ^ 2) == -1) == std::complex<double>(0, 1) || solve((x ^ 2) == -1) == std::complex<double>(0, -1)));
    CHECK((solve((x ^ 2) == -49) == std::complex<double>(0, 7) || solve((x ^ 2) == -1) == std::complex<double>(0, -7)));
    CHECK((solve((x ^ 2) == -36) == std::complex<double>(0, 6) || solve((x ^ 2) == -1) == std::complex<double>(0, -6)));
    CHECK((solve((x ^ 2) == -100) == std::complex<double>(0, 10) || solve((x ^ 2) == -1) == std::complex<double>(0, -10)));
    CHECK((solve((x ^ 2) == -9) == std::complex<double>(0, 3) || solve((x ^ 2) == -1) == std::complex<double>(0, -3)));
    CHECK((solve((x ^ 2) == -25) == std::complex<double>(0, 5) || solve((x ^ 2) == -1) == std::complex<double>(0, -5)));
    CHECK((solve((x ^ 2) == -64) == std::complex<double>(0, 8) || solve((x ^ 2) == -1) == std::complex<double>(0, -8)));
    CHECK((solve((x ^ 2) == -81) == std::complex<double>(0, 9) || solve((x ^ 2) == -1) == std::complex<double>(0, -9)));
    CHECK((solve((x ^ 2) == -4) == std::complex<double>(0, 2) || solve((x ^ 2) == -1) == std::complex<double>(0, -2)));
};
