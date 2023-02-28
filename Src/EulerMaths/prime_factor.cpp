/*******************************************************************************
* Source file containing all functions related to prime numbers.               *
*******************************************************************************/

#include "prime_factor.h"

/*  Sieve of Eratosthenes
    Algorithm to find all prime numbers up to any given limit
    Inputs  : - a limit [int]
    Outputs : - a vector telling if k is a prime or not [std::vector<bool>]
*/
std::vector<bool> sieveOfEratosthenes(int n)
{
    /* entry requirement */
    if (n < 0)
    {
        std::cerr << "Error : entry requirement not met.\n"
                     "Function : sieveOfEratosthenes\n"
                     "Solution : n should be positive\n";
        return std::vector<bool>();
    }

    if (n == 0)
        return std::vector<bool>(1, false);
    else if (n == 1)
        return std::vector<bool>(2, false);

    /* initialize all values to true */
    std::vector<bool> is_prime_factor_vector(n+1, true);

    /* set false to all even numbers above 2 */
    for (int k = 4; k < n+1; k+=2)
    {
        is_prime_factor_vector[k] = false;
    }

    /* set 0 and 1 to false */
    is_prime_factor_vector[0] = false;
    is_prime_factor_vector[1] = false;

    /* We delete all the multiples of an integer (other than itself) */
    int k = 3;
    while (k*k < n+1)
    {
        if (is_prime_factor_vector[k])
        {
            for (int i = k*k; i < n+1; i += 2*k)
            {
                is_prime_factor_vector[i] = false;
            }
        }
        k++;
    }

    return is_prime_factor_vector;
}

/*  Sieve of Sundaram
    Variant of the sieve of Eratosthenes for finding all prime numbers up to a limit
    Inputs  : - a limit [int]
    Outputs : - a vector telling if k is a prime or not [std::vector<bool>]
*/
std::vector<bool> sieveOfSundaram(int n)
{
    /* entry requirement */
    if (n < 2)
    {
        std::cerr << "Error : entry requirement not met.\n"
                     "Function : sieveOfSundaram\n"
                     "Solution : n should be greater than 1\n";
        return std::vector<bool>();
    }

    int n_half = (n-1)/2;

    /* initialize all values to true */
    std::vector<bool> is_prime_factor_vector(n+1, false);


    /* We eliminate all numbers of the form k + i + 2*k*i */
    std::vector<bool> marked(n_half+1, false);
    for (long int k = 1; k < n_half + 1; k++)
    {
        for (long int i = k; (k + i + 2*k*i) < n_half + 1; i++)
        {
            marked[k + i + 2*k*i] = true;
        }
    }

    /* The remaining numbers are doubled and then incremented. They are primes */
    is_prime_factor_vector[2] = true;
    for (int k = 1; k < n_half+1; k++)
    {
        if (!marked[k])
        {
            is_prime_factor_vector[2*k+1] = true;
        }
    }

    return is_prime_factor_vector;
}

/*  Primality test
    Function to check if a number is a prime factor
    Inputs  : - a number [int]
    Outputs : - a boolean value [bool]
*/
bool isPrimeFactor(int n)
{
    /* entry requirement */
    if (n < 2)
    {
        std::cerr << "Error : entry requirement not met.\n"
                     "Function : isPrimeFactor\n"
                     "Solution : n should be greater than 1\n";
        return false;
    }

    /* compute the prime factors until the square root of n */
    int root_n = floor(sqrt(n));
    std::vector<bool> is_prime_factor_vector = sieveOfEratosthenes(root_n);

    /* check if n is divisible by some prime factors */
    for (int k = 2; k < root_n + 1; k++)
    {
        if (is_prime_factor_vector[k])
        {
            if (n % k == 0)
                return false;
        }
    }

    return true;
}

/*  Prime factor decomposition
    Compute the prime factor decomposition of an integer value
    Inputs  : - a number [int]
    Outputs : - a map with the factors and their exponents [std::map<int,int>]
*/
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