#include <cassert>
#include <functional>

#include "factorial.hpp"

void testFactorial(std::function<unsigned long(int)> factorial_impl)
{
    assert(factorial_impl(0) == 1);
    assert(factorial_impl(1) == 1);
    assert(factorial_impl(2) == 2);
    assert(factorial_impl(3) == 6);
    assert(factorial_impl(4) == 24);
    assert(factorial_impl(5) == 120);
    assert(factorial_impl(6) == 720);
    assert(factorial_impl(7) == 5040);
}

int main()
{
    testFactorial(runtime::iterative::factorial);
    testFactorial(runtime::stl_algo::factorial);
    testFactorial(runtime::functional::factorial);
    testFactorial(compiletime::factorial);

    return 0;
}
