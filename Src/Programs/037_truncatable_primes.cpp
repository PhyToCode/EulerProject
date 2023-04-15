/*******************************************************************************
* Problem 37 : Truncatable primes                                              * 
*                                                                              *
* The number 3797 has an interesting property. Being prime itself, it is       *
* possible to continuously remove digits from left to right, and remain prime  *
* at each stage: 3797, 797, 97, and 7.                                         *
* Similarly we can work from right to left: 3797, 379, 37, and 3.              *
*                                                                              *
* Find the sum of the only eleven primes that are both truncatable from left   *
* to right and right to left.                                                  *
*                                                                              *
* NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.            *
*******************************************************************************/

#include <eulermaths.h>
#include <prime_factor.h>

bool isTruncatable(int prime, std::vector<bool> &is_prime_numbers)
{
    bool result = true;
    int power_ten = 10;
    int remainder = prime%power_ten;

    /* Reading from left to right */
    while (remainder != prime && result == true)
    {
        if (is_prime_numbers[remainder] == false)
        {
            result = false;
        }
        power_ten *= 10;
        remainder = prime%power_ten;
    }

    power_ten = 10;

    /* Reading from right to left */
    while (remainder >= 10 && result == true)
    {
        remainder = prime/power_ten;
        if (is_prime_numbers[remainder] == false)
        {
            result = false;
        }
        power_ten *= 10;
    }

    return result;
}

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 2)
    {
        std::cerr << "Usage : ./037_truncatable_primes n" << std::endl;
        return -1;
    }

    const int n = std::stoi(argv[1]);
    int nb_curent_truncatable_primes = 0;
    int nb_max_truncatable_primes = 11;
    std::vector<int> vec_truncatable_primes;
    int k = 11;
    int sum = 0;
    std::vector<bool> is_prime_numbers = sieveOfEratosthenes(n);

    while (nb_curent_truncatable_primes < nb_max_truncatable_primes && k < n)
    {
        if (is_prime_numbers[k] == true)
        {
            if (isTruncatable(k, is_prime_numbers))
            {
                vec_truncatable_primes.push_back(k);
                nb_curent_truncatable_primes++;
                sum += k;
            }
        }
        k++;
    }

    /* Display of results */
    if (nb_curent_truncatable_primes < nb_max_truncatable_primes)
    {
        std::cout << "We couldn't compute the sum because we didn't find the eleven primes that are";
        std::cout << " truncatable.\nPlease, restart the program with a higher threshold n\n";
    }
    else
    {
        std::cout << "The sum of the only eleven primes that are both truncatable from left";
        std::cout << " to right and right to left is " << sum << std::endl;
        std::cout << "These eleven prime numbers are : { ";
        for (int i = 0; i < 11; i++)
        {
            std::cout << vec_truncatable_primes[i] << " ";
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}