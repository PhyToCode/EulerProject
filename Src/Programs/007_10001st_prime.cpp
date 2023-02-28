/*******************************************************************************
* Problem 7 : 10001st prime                                                    *
*                                                                              *
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see   *
* that the 6th prime is 13.                                                    *
*                                                                              *
* What is the 10 001st prime number?                                           *
*******************************************************************************/

#include <eulermaths.h>
#include <prime_factor.h>

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 2)
    {
        std::cerr << "Usage : ./007_10001st_prime n" << std::endl;
        return -1;
    }

    const long unsigned int n = std::stol(argv[1]);

    std::vector<long int> prime_factor_vector = {2};
    bool pf;
    long int k = 3;

    /* Recovery of the first prime factors */
    while (prime_factor_vector.size() < n)
    {
        pf = isPrimeFactor(k);
        if (pf == true)
            prime_factor_vector.push_back(k);
        k++;
    }

    /* Display of results */
    std::cout << "The " << n << "st prime number is " << prime_factor_vector.back() << std::endl;

    return 0;
}