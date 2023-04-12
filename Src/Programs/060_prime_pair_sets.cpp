/*******************************************************************************
* Problem 60 : Prime pair sets                                                 *
*                                                                              *
* The primes 3, 7, 109, and 673, are quite remarkable. By taking any two       *
* primes and concatenating them in any order the result will always be prime.  *
* For example, taking 7 and 109, both 7109 and 1097 are prime.                 *
* The sum of these four primes, 792, represents the lowest sum for a set of    *
* four primes with this property.                                              *
*                                                                              *
* Find the lowest sum for a set of five primes for which any two primes        *
* concatenate to produce another prime.                                        *
*******************************************************************************/

#include <eulermaths.h>
#include <prime_factor.h>

#define THRESHOLD_ERATO 100000000
#define THRESHOLD_PRIME 10000

/* Function to concatenate 2 integers */
int concatenate(int a, int b)
{
    int power_ten = 10;
    while (power_ten < b)
        power_ten *= 10;
    return a*power_ten + b; 
}

/* Function to determine if a pair of int is a prime paire */
bool isPair(int a, int b, std::vector<bool> &is_prime_numbers)
{
    bool result = false;
    int ab = concatenate(a, b);
    int ba = concatenate(b, a);
    if (is_prime_numbers[ab] == true && is_prime_numbers[ba] == true)
    {
        result = true;
    }

    return result;
}

/* Function to determine if a set of 2 + 1 elements is a prime triplet set */
bool isTriplet(std::vector<int> prime_pair, int new_value, std::vector<bool> &is_prime_numbers)
{
    bool result = true;

    for (int k = 0; k < 2; k++)
    {
        result = isPair(prime_pair[k], new_value, is_prime_numbers);
        if (result == false)
            break;
    }

    return result;
}

/* Function to determine if a set of 3 + 1 elements is a prime quadruplet set */
bool isQuadruplet(std::vector<int> prime_triplet, int new_value, std::vector<bool> &is_prime_numbers)
{
    bool result = true;

    for (int k = 0; k < 3; k++)
    {
        result = isPair(prime_triplet[k], new_value, is_prime_numbers);
        if (result == false)
            break;
    }

    return result;
}

/* Function to determine if a set of 4 + 1 elements is a prime quintuplet set */
bool isQuintuplet(std::vector<int> prime_quadruplet, int new_value, std::vector<bool> &is_prime_numbers)
{
    bool result = true;

    for (int k = 0; k < 4; k++)
    {
        result = isPair(prime_quadruplet[k], new_value, is_prime_numbers);
        if (result == false)
            break;
    }

    return result;
}

/* Function listing all the primes with which a (itself prime) form a prime pair */
std::vector<int> listPrimePairs (int a, int id, std::vector<int> prime_numbers, std::vector<bool> &is_prime_numbers)
{
    std::vector<int> vec_prime_pairs = {};

    for (int k = id + 1; k < int(prime_numbers.size()); k++)
    {
        int b = prime_numbers[k];
        if (isPair(a, b, is_prime_numbers))
        {
            vec_prime_pairs.push_back(b);
        }
    }

    return vec_prime_pairs;
}


int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 1)
    {
        std::cerr << "Usage : ./060_prime_pair_sets" << std::endl;
        return -1;
    }

    std::vector<std::vector<int>> vec_prime_quintuplet;
    std::vector<int> vec_sum_prime_quintuplet;

    /* We get the boolean vector of the first THRESHOLD numbers to know if they are prime or not */
    std::vector<bool> is_prime_numbers = sieveOfEratosthenes(THRESHOLD_ERATO);

    /* We recover all the prime numbers */
    std::vector<int> prime_numbers = {};
    for (int k = 0; k < THRESHOLD_PRIME; k++)
    {
        if (is_prime_numbers[k] == true)
        {
            prime_numbers.push_back(k);
        }
    }

    /* assemble pairs of prime numbers */
    for (int k = 0; k < int(prime_numbers.size()); k++)
    {
        int a = prime_numbers[k];

        /* We get all pairs of which a is part */
        std::vector<int> prime_pairs_with_a = listPrimePairs(a, k, prime_numbers, is_prime_numbers);

        int vec_size = prime_pairs_with_a.size();

        /* We recover all prime quintuplets */
        for (int j = 0; j < vec_size - 3; j++)
        {
            int b = prime_pairs_with_a[j];
            std::vector<int> set = {a, b};

            for (int j2 = j + 1; j2 < vec_size - 2; j2++)
            {
                int c = prime_pairs_with_a[j2];
                if (!isTriplet(set, c, is_prime_numbers))
                {
                    continue;
                }
                else
                {
                    set.push_back(c);
                    for (int j3 = j2 + 1; j3 < vec_size - 1; j3++)
                    {
                        int d = prime_pairs_with_a[j3];
                        if (!isQuadruplet(set, d, is_prime_numbers))
                        {
                            continue;
                        }
                        else
                        {
                            set.push_back(d);
                            for (int j4 = j3 + 1; j4 < vec_size; j4++)
                            {
                                int e = prime_pairs_with_a[j4];
                                if (!isQuintuplet(set, e, is_prime_numbers))
                                {
                                    continue;
                                }
                                else
                                {
                                    set.push_back(e);
                                    vec_prime_quintuplet.push_back(set);
                                    vec_sum_prime_quintuplet.push_back(a+b+c+d+e);
                                    set.pop_back();
                                }
                            }
                            set.pop_back();
                        }
                    }
                    set.pop_back();
                }
            }
        }
    }

    /* Compute the minimum sum */
    std::vector<int>::iterator result = std::min_element(vec_sum_prime_quintuplet.begin(), vec_sum_prime_quintuplet.end());
    long int dist = std::distance(vec_sum_prime_quintuplet.begin(), result);

    /* Display of results */
    std::cout << "The lowest sum for a set of five primes for which any two primes concatenate produce another prime is " << *result << std::endl;
    std::cout << "The quintuplet is {" << vec_prime_quintuplet[dist][0] << ", " << vec_prime_quintuplet[dist][1] << ", ";
    std::cout << vec_prime_quintuplet[dist][2] << ", " << vec_prime_quintuplet[dist][3] << ", " << vec_prime_quintuplet[dist][4] << "}" << std::endl;

    return 0;
}