/*******************************************************************************
* Problem 1 : Multiples of 3 or 5                                              *
*                                                                              *
* If we list all the natural numbers below 10 that are multiples of 3 or 5,    *
* we get 3, 5, 6 and 9. The sum of these multiples is 23.                      *
*                                                                              *
* Find the sum of all the multiples of 3 or 5 below 1000.                      *
*******************************************************************************/

#include <eulermaths.h>

#define THREE   3
#define FIVE    5
#define FIFTEEN 15
#define THIRTY  30

int sumOfMultiplesOfMBelowN(const int m, const int n)
{
    int sum = 0;
    for (int k = m; k < n; k+=m)
    {
        sum += k;
    }

    return sum;
}

//> First Method : sum multiples of 3 and 5 minus multiples of 3*5 = 15
int firstMethod(const int n)
{
    int sum = 0;
    sum += sumOfMultiplesOfMBelowN(THREE, n);
    sum += sumOfMultiplesOfMBelowN(FIVE, n);
    sum -= sumOfMultiplesOfMBelowN(FIFTEEN, n);

    return sum;
}

//> Second Method : the pattern
int secondMethod(const int n)
{
    int sum_1 = 0;
    int sum_2 = 0;
    int sum_3 = 0;
    const std::vector<int> pattern = {3, 5, 6, 9, 10, 12, 15, 18, 20, 21, 24, 25, 27, 30};
    const int size_pattern = int(pattern.size());

    int q = n / THIRTY;
    int r = n % THIRTY;

    for (int k = 1; k < q; k++)
    {
        sum_1 += k;
    }
    sum_1 *= size_pattern * THIRTY;

    for (int k = 0; k < size_pattern; k++)
    {
        int value = pattern [k];
        sum_2 += value;
        if (value < r)
        {
            sum_3 += q * THIRTY + value;
        }
    }
    sum_2 *= q;

    return sum_1 + sum_2 + sum_3;
}



int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 2)
    {
        std::cerr << "Usage : ./001_multiples_of_3_or_5 n" << std::endl;
        return -1;
    }

    const int n = atoi(argv[1]);

    /* Variable declaration */
    int sum_1 = 0;
    int sum_2 = 0;

    /* First method */
    auto start = std::chrono::steady_clock::now();
    sum_1 = firstMethod(n);
    auto end = std::chrono::steady_clock::now();
    auto cpt_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    /* Second method */
    start = std::chrono::steady_clock::now();
    sum_2 = secondMethod(n);
    end = std::chrono::steady_clock::now();
    auto cpt_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  

    /* Display of results */
    std::cout << "Result 1 : " << sum_1 << " | Computation Time : " << cpt_1 << " ns" << std::endl;
    std::cout << "Result 2 : " << sum_2 << " | Computation Time : " << cpt_2 << " ns" << std::endl;

    return 0;
}