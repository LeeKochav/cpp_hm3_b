#include "solver.hpp"
#include <stdexcept>
#include <cmath>
using namespace solver;

/*
    RealVariable Class implemention:
*/

// Operator *:
RealVariable &RealVariable::operator*(double coe) const
{
    RealVariable *res = new RealVariable(coe * m_a, coe * m_b, coe * m_c);
    return *res;
}

RealVariable &RealVariable::operator*(const RealVariable &other) const
{
    // Handle the power > 2
    if (m_a * other.m_a != 0 || (m_a * other.m_b + m_b * other.m_a) != 0)
    {
        throw runtime_error("Power cannot be greater then 2!");
    }
    double a = m_a * other.m_c + m_b * other.m_b + m_c * other.m_a;
    double b = m_b * other.m_c + m_c * other.m_b;
    double c = m_c * other.m_c;

    RealVariable *res = new RealVariable(a, b, c);
    return *res;
}

RealVariable &solver::operator*(double coe, const RealVariable &other) //friend
{
    RealVariable *res = new RealVariable(coe * other.m_a, coe * other.m_b, coe * other.m_c);
    return *res;
}

// Operator +:
RealVariable &RealVariable::operator+(double coe)
{
    RealVariable *res = new RealVariable(m_a, m_b, coe + m_c);
    return *res;
}

RealVariable &RealVariable::operator+(const RealVariable &other)
{
    RealVariable *res = new RealVariable(m_a + other.m_a, m_b + other.m_b, m_c + other.m_c);
    return *res;
}

RealVariable &solver::operator+(double coe, const RealVariable &other)
{
    RealVariable *res = new RealVariable(other.m_a, other.m_b, coe + other.m_c);
    return *res;
}

// Operator ==:
RealVariable &RealVariable::operator==(double coe) const
{
    RealVariable *res = new RealVariable(m_a, m_b, m_c - coe);
    return *res;
}

RealVariable &RealVariable::operator==(const RealVariable &other) const
{
    RealVariable *res = new RealVariable(m_a - other.m_a, m_b - other.m_b, m_c - other.m_c);
    return *res;
}

RealVariable &solver::operator==(double coe, const RealVariable &other)
{
    RealVariable *res = new RealVariable(other.m_a, other.m_b, other.m_c - coe);
    return *res;
}

// Operator -:
RealVariable &RealVariable::operator-(double coe)
{
    RealVariable *res = new RealVariable(m_a, m_b, m_c - coe);
    return *res;
}

RealVariable &RealVariable::operator-(const RealVariable &other)
{
    RealVariable *res = new RealVariable(m_a - other.m_a, m_b - other.m_b, m_c - other.m_c);
    return *res;
}

RealVariable &solver::operator-(double coe, const RealVariable &other)
{
    RealVariable *res = new RealVariable(-other.m_a, -other.m_b, coe - other.m_c);
    return *res;
}

// Operator /:
RealVariable &RealVariable::operator/(double coe)
{
    if (coe == 0)
    {
        throw runtime_error("Cannot divide by 0!");
    }

    RealVariable *res = new RealVariable(m_a / coe, m_b / coe, m_c / coe);
    return *res;
}

RealVariable &solver::operator/(double coe, const RealVariable &other)
{
    if (other.m_a == 0 || other.m_b == 0 || other.m_c == 0)
    {
        throw runtime_error("Cannot divide by 0!");
    }

    RealVariable *res = new RealVariable(coe / other.m_a, coe / other.m_b, coe / other.m_c);
    return *res;
}

// Operator ^:
RealVariable &RealVariable::operator^(int pow)
{
    RealVariable *res;
    if (pow < 0 || pow > 2 || (m_a != 0 && pow > 1))
    {
        throw runtime_error("Power cannot be greater then 2 or less then 0!");
    }

    if (pow == 0)
    {
        res = new RealVariable(0, 0, 1);
    }
    else if (pow == 1)
    {
        res = new RealVariable(m_a, m_b, m_c);
    }
    else
    {
        RealVariable x(m_a, m_b, m_c);
        RealVariable y(m_a, m_b, m_c);
        res = &(x * y);
    }
    return *res;
}

// Solve:
double solver::solve(const RealVariable &rv)
{
    if (rv.getA() == 0 && rv.getB() == 0 && rv.getC() == 0)
    {
        throw runtime_error("Infinite Solutions!");
    }

    if (rv.getA() == 0)
    {
        if (rv.getB() == 0)
        {
            throw runtime_error("No Solution!");
        }
        return (-rv.getC()) / rv.getB();
    }

    double delta = pow(rv.getB(), 2) - 4 * rv.getA() * rv.getC();

    if (delta < 0)
    {
        throw runtime_error("No Solution!");
    }

    return ((-rv.getB()) + sqrt(delta)) / (2 * rv.getA());
}

/*
    ComplexVariable Class implemention:
*/

// Operator *:
ComplexVariable &ComplexVariable::operator*(std::complex<double> cmplx_coe)
{
    ComplexVariable *res = new ComplexVariable(m_a * cmplx_coe, m_b * cmplx_coe, m_c * cmplx_coe);
    return *res;
}

ComplexVariable &ComplexVariable::operator*(double coe)
{
    std::complex<double> cmplx_coe = std::complex<double>(coe, 0);
    ComplexVariable tmp(m_a, m_b, m_c);
    ComplexVariable *res = &(tmp * cmplx_coe);
    return *res;
}

ComplexVariable &ComplexVariable::operator*(const ComplexVariable &other)
{
    std::complex<double> zero = std::complex<double>(0, 0);
    // Handle the power > 2
    if (m_a * other.m_a != zero || (m_a * other.m_b + m_b * other.m_a) != zero)
    {
        throw runtime_error("Power cannot be greater then 2!");
    }
    std::complex<double> a = m_a * other.m_c + m_b * other.m_b + m_c * other.m_a;
    std::complex<double> b = m_b * other.m_c + m_c * other.m_b;
    std::complex<double> c = m_c * other.m_c;

    ComplexVariable *res = new ComplexVariable(a, b, c);
    return *res;
}

ComplexVariable &solver::operator*(std::complex<double> cmplx_coe, const ComplexVariable &other) // friend
{
    ComplexVariable *res = new ComplexVariable(other.m_a * cmplx_coe, other.m_b * cmplx_coe, other.m_c * cmplx_coe);
    return *res;
}

ComplexVariable &solver::operator*(double coe, const ComplexVariable &other) //friend
{
    std::complex<double> cmplx_coe = std::complex<double>(coe, 0);
    ComplexVariable tmp(other.m_a, other.m_b, other.m_c);
    ComplexVariable *res = &(tmp * cmplx_coe);
    return *res;
}

// Operator +:
ComplexVariable &ComplexVariable::operator+(std::complex<double> cmplx_coe)
{
    ComplexVariable *res = new ComplexVariable(m_a, m_b, m_c + cmplx_coe);
    return *res;
}

ComplexVariable &ComplexVariable::operator+(double coe)
{
    ComplexVariable *res = new ComplexVariable(m_a, m_b, m_c + coe);
    return *res;
}

ComplexVariable &ComplexVariable::operator+(const ComplexVariable &other)
{
    ComplexVariable *res = new ComplexVariable(m_a + other.m_a, m_b + other.m_b, m_c + other.m_c);
    return *res;
}

ComplexVariable &solver::operator+(std::complex<double> cmplx_coe, const ComplexVariable &other) //friend
{
    ComplexVariable *res = new ComplexVariable(other.m_a, other.m_b, other.m_c + cmplx_coe);
    return *res;
}

ComplexVariable &solver::operator+(double coe, const ComplexVariable &other) //friend
{
    ComplexVariable *res = new ComplexVariable(other.m_a, other.m_b, other.m_c + coe);
    return *res;
}

// Operator ==:
ComplexVariable &ComplexVariable::operator==(std::complex<double> cmplx_coe)
{
    ComplexVariable *res = new ComplexVariable(m_a, m_b, m_c - cmplx_coe);
    return *res;
}

ComplexVariable &ComplexVariable::operator==(double coe)
{
    ComplexVariable *res = new ComplexVariable(m_a, m_b, m_c - coe);
    return *res;
}

ComplexVariable &ComplexVariable::operator==(const ComplexVariable &other)
{
    ComplexVariable *res = new ComplexVariable(m_a - other.m_a, m_b - other.m_b, m_c - other.m_c);
    return *res;
}

ComplexVariable &solver::operator==(std::complex<double> cmplx_coe, const ComplexVariable &other) //friend
{
    ComplexVariable *res = new ComplexVariable(other.m_a, other.m_b, other.m_c - cmplx_coe);
    return *res;
}

ComplexVariable &solver::operator==(double coe, const ComplexVariable &other) //friend
{
    ComplexVariable *res = new ComplexVariable(other.m_a, other.m_b, other.m_c - coe);
    return *res;
}

// Operator -:
ComplexVariable &ComplexVariable::operator-(double coe)
{
    ComplexVariable *res = new ComplexVariable(m_a, m_b, m_c - coe);
    return *res;
}

ComplexVariable &ComplexVariable::operator-(const ComplexVariable &other)
{
    ComplexVariable *res = new ComplexVariable(m_a - other.m_a, m_b - other.m_b, m_c - other.m_c);
    return *res;
}

ComplexVariable &ComplexVariable::operator-(std::complex<double> cmplx_coe)
{
    ComplexVariable *res = new ComplexVariable(m_a, m_b, m_c - cmplx_coe);
    return *res;
}

ComplexVariable &solver::operator-(std::complex<double> cmplx_coe, const ComplexVariable &other) //friend
{
    ComplexVariable *res = new ComplexVariable(-other.m_a, -other.m_b, cmplx_coe - other.m_c);
    return *res;
}

ComplexVariable &solver::operator-(double coe, const ComplexVariable &other) //friend
{
    ComplexVariable *res = new ComplexVariable(-other.m_a, -other.m_b, coe - other.m_c);
    return *res;
}

// Operator /:
ComplexVariable &ComplexVariable::operator/(double coe)
{
    if (coe == 0)
    {
        throw runtime_error("Cannot divide by 0!");
    }

    ComplexVariable *res = new ComplexVariable(m_a / coe, m_b / coe, m_c / coe);
    return *res;
}

ComplexVariable &ComplexVariable::operator/(std::complex<double> cmplx_coe)
{
    if (cmplx_coe == std::complex<double>(0, 0))
    {
        throw runtime_error("Cannot divide by 0!");
    }

    ComplexVariable *res = new ComplexVariable(m_a / cmplx_coe, m_b / cmplx_coe, m_c / cmplx_coe);
    return *res;
}

ComplexVariable &solver::operator/(std::complex<double> cmplx_coe, const ComplexVariable &other) //friend
{
    std::complex<double> zero = std::complex<double>(0, 0);
    if (other.m_a == zero || other.m_b == zero || other.m_c == zero)
    {
        throw runtime_error("Cannot divide by 0!");
    }
    ComplexVariable *res = new ComplexVariable(cmplx_coe / other.m_a, cmplx_coe / other.m_b, cmplx_coe / other.m_c);
    return *res;
}

ComplexVariable &solver::operator/(double coe, const ComplexVariable &other) //friend
{
    std::complex<double> zero = std::complex<double>(0, 0);
    if (other.m_a == zero || other.m_b == zero || other.m_c == zero)
    {
        throw runtime_error("Cannot divide by 0!");
    }
    ComplexVariable *res = new ComplexVariable(coe / other.m_a, coe / other.m_b, coe / other.m_c);
    return *res;
}

// Operator ^:
ComplexVariable &ComplexVariable::operator^(int pow)
{
    ComplexVariable *res;
    if (pow < 0 || pow > 2 || (m_a != std::complex<double>(0, 0) && pow > 1))
    {
        throw runtime_error("Power cannot be greater then 2 or less then 0!");
    }

    if (pow == 0)
    {
        res = new ComplexVariable(0, 0, 1);
        return *res;
    }
    else if (pow == 1)
    {
        res = new ComplexVariable(m_a, m_b, m_c);
        return *res;
    }
    else
    {
        ComplexVariable x(m_a, m_b, m_c);
        ComplexVariable y(m_a, m_b, m_c);
        res = &(x * y);
        return *res;
    }
}

// Solve:
std::complex<double> solver::solve(const ComplexVariable &cv)
{
    std::complex<double> zero = std::complex<double>(0, 0);
    if (cv.getA() == zero && cv.getB() == zero && cv.getC() == zero)
    {
        throw runtime_error("Infinite Solutions!");
    }

    if (cv.getA() == zero)
    {
        if (cv.getB() == zero)
        {
            throw runtime_error("No Solution!");
        }
        return (-cv.getC()) / cv.getB();
    }

    std::complex<double> delta = pow(cv.getB(), 2) - 4.0 * cv.getA() * cv.getC();

    return ((-cv.getB()) + sqrt(delta)) / (2.0 * cv.getA());
}