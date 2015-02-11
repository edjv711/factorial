#include "factorial.hpp"

#include <vector>
#include <numeric>
#include <functional>
#include <map>
#include <stdexcept>

namespace runtime
{
    namespace iterative
    {
        unsigned long factorial(int n)
        {
            unsigned long result = 1;
            for (int i = 1; i <= n; ++i)
            {
                result *= i;
            }
            return result;
        }
    }

    namespace recursive
    {
        unsigned long factorial(int n)
        {
            return n == 0 ? 1 : n * factorial(n - 1);
        }
    }

    namespace stl_algo
    {
        unsigned long factorial(int n)
        {
            std::vector<unsigned long> nums;
            nums.resize(n);
            std::iota(nums.begin(), nums.end(), 1);
            return std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<unsigned long>());
        }
    }
}

namespace compiletime
{
    template<int n>
    struct Factorial
    {
        static const unsigned long value = n * Factorial<n - 1>::value;
    };

    template<>
    struct Factorial<0>
    {
        static const unsigned long value = 1;
    };

    static std::map<int, unsigned long> factorialTable;

    struct InitFactorials
    {
        InitFactorials()
        {
            #define INIT_FACTORIAL(n) factorialTable[n] = Factorial<n>::value
            INIT_FACTORIAL(0);
            INIT_FACTORIAL(1);
            INIT_FACTORIAL(2);
            INIT_FACTORIAL(3);
            INIT_FACTORIAL(4);
            INIT_FACTORIAL(5);
            INIT_FACTORIAL(6);
            INIT_FACTORIAL(7);
            #undef INIT_FACTORIAL
        }
    };

    static InitFactorials initFactorials;

    unsigned long factorial(int n)
    {
        if (factorialTable.find(n) == factorialTable.end())
        {
            throw std::logic_error("factorial value was not statically initialized!");
        }
        return factorialTable[n];
    }
}
