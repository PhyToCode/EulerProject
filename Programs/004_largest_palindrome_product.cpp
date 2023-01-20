/*******************************************************************************
* Problem 4 : Largest palindrome product                                       *
*                                                                              *
* A palindromic number reads the same both ways. The largest palindrome made   *
* from the product of two 2-digit numbers is 9009 = 91 × 99.                   *
*                                                                              *
* Find the largest palindrome made from the product of two 3-digit numbers.    *
*******************************************************************************/

#include <iostream>

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 2)
    {
        std::cout << "Usage : ./004_largest_palindrome_product" << std::endl;
        return -1;
    }

    /* Display of results */
    std::cout << "Result of Problem 4 : " << std::endl;
    std::cout << "The largest palindrome product is " << std::endl;

    return 0;
}