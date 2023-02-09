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

#include <iostream>
#include <vector>
#include <cmath>

/* Compute the sum of the squares of several integer values */
int sumOfSquares(std::vector<int> numbers)
{
    int sum = 0;
    for (int k = 0; k < numbers.size(); k++)
    {
        sum += pow(numbers[k], 2);
    }

    return sum;
}

/* Compute square of the sum of several integer values */
int squareOfSum(std::vector<int> numbers)
{
    int sum = 0;
    for (int k = 0; k < numbers.size(); k++)
    {
        sum += numbers[k];
    }

    sum *= sum;

    return sum;
}

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 1)
    {
        std::cerr << "Usage : ./006_sum_square_difference" << std::endl;
        return -1;
    }

    std::vector<int> hundred;

    for (int k = 1; k < 101; k++)
    {
        hundred.push_back(k);
    }

    /* Display of results */
    std::cout << "Result of Problem 6 : " << abs(sumOfSquares(hundred) - squareOfSum(hundred)) << std::endl;

    return 0;
}