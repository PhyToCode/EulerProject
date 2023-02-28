/*******************************************************************************
* Problem 10 : Summation of primes                                              *
*                                                                              *
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.                        *
*                                                                              *
* Find the sum of all the primes below two million.                            *
*******************************************************************************/

#include <eulermaths.h>
#include <prime_factor.h>

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 2)
    {
        std::cerr << "Usage : ./010_summation_of_primes n" << std::endl;
        return -1;
    }

    const int n = std::stoi(argv[1]);

    /* Variable declaration */
    long long int sum = 0;

    /* Recovery of the prime factors */
    std::vector<bool> era = sieveOfEratosthenes(n);

    for (int k = 0; k < n + 1 ; k++)
    {
        if (era[k])
        {
            sum += k;
        }
    }

    /* Display of results */
    std::cout << "The sum of the primes below " << n << " is " << sum << std::endl;

    return 0;
}