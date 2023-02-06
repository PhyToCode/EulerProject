/*******************************************************************************
* Problem 4 : Largest palindrome product                                       *
*                                                                              *
* A palindromic number reads the same both ways. The largest palindrome made   *
* from the product of two 2-digit numbers is 9009 = 91 × 99.                   *
*                                                                              *
* Find the largest palindrome made from the product of two 3-digit numbers.    *
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool checkPalindrome(int nb)
{
    int reverse = 0; // reverse of the nb number 
    int temp = nb;   // temporary value
    while (temp != 0)
    {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse == nb);
}

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 2)
    {
        std::cout << "Usage : ./004_largest_palindrome_product digits" << std::endl;
        return -1;
    }

    int digits = atoi(argv[1]);
    std::vector<int> palindrom_vector;
    int product;

    int max_range = pow(10, digits) - 1;
    int min_range = pow(10, digits - 1) - 1;

    /* We check if the numbers are palindromes */
    for (int k = max_range; k > min_range; k--)
    {
        for (int i = max_range; i > min_range; i--)
        {
            product = k*i;
            if (checkPalindrome(product) == 1)
            {
                palindrom_vector.push_back(product);
            }
        }
    }

    int max_palindrom = *std::max_element(palindrom_vector.begin(), palindrom_vector.end());

    /* Display of results */
    std::cout << "Result of Problem 4 : " << std::endl;
    std::cout << "The largest palindrome product of two " << digits << "-digit number is " << max_palindrom << std::endl;

    return 0;
}