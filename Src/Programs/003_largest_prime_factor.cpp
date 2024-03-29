/*******************************************************************************
* Problem 3 : Largest Prime Factor                                             *
*                                                                              *
* The prime factors of 13195 are 5, 7, 13 and 29.                              *
*                                                                              *
* What is the largest prime factor of the number 600851475143 ?                *
*******************************************************************************/

#include <eulermaths.h>
#include <prime_factor.h>

#define TEN_THOUSAND 10000

int main (int argc, char *argv[])
{

    /* Input processing */
    if (argc != 2)
    {
        std::cerr << "Usage : ./003_largest_prime_factor n" << std::endl;
        return -1;
    }

    const long int n = std::stol(argv[1]);

    /* Variable declaration */
    std::vector<long int> prime_factor_vector = {2};
    std::vector<long int> decomposition;
    long int value = n;
    bool pf;

    /* Recovery of the first prime factors */
    for (long int k = 3; k < TEN_THOUSAND; k++)
    {
        pf = isPrimeFactor(k);
        if (pf == true)
            prime_factor_vector.push_back(k);
    }

    /* Decomposition of n into prime factors */
    while (value != 1)
    {
        int k = 0;
        long int pfactor = prime_factor_vector[k];
        while (value % pfactor != 0)
        {
            k++;
            pfactor = prime_factor_vector[k];
        }
        decomposition.push_back(pfactor);
        value /= pfactor;
        k = 0;
    }

    /* Display of results */
    std::cout << "The largest prime factor of the number " << n << " is " << decomposition.back() << std::endl;

    return 0;
}