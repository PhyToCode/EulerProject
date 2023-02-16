/*******************************************************************************
* Problem 5 : Smallest multiple                                                *
*                                                                              *
* 2520 is the smallest number that can be divided by each of the numbers from  *
* 1 to 10 without any remainder.                                               *
*                                                                              *
* What is the smallest positive number that is evenly divisible by all of the  *
* numbers from 1 to 20?                                                        *
*******************************************************************************/

#include <eulermaths.h>

/* Compute the prime factor decomposition of an integer value */
std::map<int,int> primeFactorDecomposition(int value)
{
    std::map<int,int> prime_factors;
    int k = 2;
    int exponent;

    while (value != 1)
    {
        exponent = 0;
        while (value % k == 0)
        {
            value = value / k;
            exponent += 1;
        }
        if (exponent != 0)
        {
            prime_factors[k] = exponent;
        }
        k++;
    }

    return prime_factors;
}

/* Compute the least commun multiple of 2 integer values */
int lcm(int a, int b)
{
    std::map<int,int> decomp_a = primeFactorDecomposition(a);
    std::map<int,int> decomp_b = primeFactorDecomposition(b);
    int p = 1;

    for (auto it = decomp_a.begin(); it != decomp_a.end(); it++)
    {
        int factor_a = it->first;
        int exponent_a = it->second;
        int exponent_b = decomp_b.find(factor_a)->second;

        if (exponent_b == 0)
        {
            p *= pow(factor_a, exponent_a);
        }
        else
        {
            p *= pow(factor_a, std::max(exponent_a, exponent_b));
            decomp_b.erase(factor_a);
        }
    }

    for (auto it = decomp_b.begin(); it != decomp_b.end(); it++)
    {
        int factor_b = it->first;
        int exponent_b = it->second;
        p *= pow(factor_b, exponent_b);
    }

    return p;
}

/* Compute the least commun multiple of several integer values */
int lcm(std::vector<int> numbers)
{
    int size = numbers.size();
    std::vector<int> numbers_lcm;

    if (size == 2)
    {
        return lcm(numbers.front(), numbers.back());
    }
    else
    {
        int k = 0;
        while (k <= size - 2)
        {
            numbers_lcm.push_back(lcm(numbers[k], numbers[k+1]));
            k += 2;
        }

        if (size % 2 != 0)
        {
            numbers_lcm.push_back(numbers.back());
        }
    }

    return lcm(numbers_lcm);
}

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 1)
    {
        std::cerr << "Usage : ./005_smallest_multiple" << std::endl;
        return -1;
    }

    int size;
    std::string string_values;

    // number of values to compute the lcm
    std::cout << "Please enter the number of values for which you want to calculate the smallest multiple : ";
    std::cin >> size;
    if (size < 2)
    {
        std::cerr << "Please, restart and give a positive value greater than 1" << std::endl;
        return -1;
    }

    // values for which we want to calculate the lcm
    std::cout << "Now, enter these " << size << " values on the next line :" << std::endl;
    std::getline(std::cin >> std::ws, string_values);

    // transform the string into a vector of integer values
    std::stringstream sstream(string_values);
    std::vector<int> lcm_values(std::istream_iterator<int>(sstream), {});

    /* Compute the smallest multiple */
    int lcm_value = lcm(lcm_values);

    /* Display of results */
    std::cout << "The smallest multiple of these numbers is : " << lcm_value << std::endl;

    return 0;
}