/*******************************************************************************
* Problem 6 : Sum square difference                                            *
*                                                                              *
* The sum of the squares of the first ten natural numbers is,                  *
*                                                                              *
*                       1² + 2² + ... + 10² = 385                              *
*                                                                              *
* The square of the sum of the first ten natural numbers is,                   *
*                                                                              *
*                   (1 + 2 + ... + 10)² = 55² = 3025                           *
*                                                                              *
* Hence the difference between the sum of the squares of the first ten natural *
* numbers and the square of the sum is 3025 - 385 = 2640.                      *
*                                                                              *
* Find the difference between the sum of the squares of the first one hundred  *
* natural numbers and the square of the sum.                                   *
*******************************************************************************/

#include <eulermaths.h>

/* Compute the sum of the squares of several integer values */
int sumOfSquares(std::vector<int> numbers)
{
    int sum = 0;
    for (long unsigned int k = 0; k < numbers.size(); k++)
    {
        sum += pow(numbers[k], 2);
    }

    return sum;
}

/* Compute square of the sum of several integer values */
int squareOfSum(std::vector<int> numbers)
{
    int sum = 0;
    for (long unsigned int k = 0; k < numbers.size(); k++)
    {
        sum += numbers[k];
    }

    sum *= sum;

    return sum;
}

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 2)
    {
        std::cerr << "Usage : ./006_sum_square_difference n" << std::endl;
        return -1;
    }

    const int N = std::stoi(argv[1]);

    std::vector<int> vector_from1_toN;

    for (int k = 1; k < N+1; k++)
    {
        vector_from1_toN.push_back(k);
    }

    /* Display of results */
    std::cout << "The difference between the sum of the squares of the first " << N;
    std::cout << " natural numbers and the square of the sum is ";
    std::cout << abs(sumOfSquares(vector_from1_toN) - squareOfSum(vector_from1_toN)) << std::endl;

    return 0;
}