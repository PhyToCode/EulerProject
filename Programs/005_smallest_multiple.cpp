/*******************************************************************************
* Problem 5 : Smallest multiple                                                *
*                                                                              *
* 2520 is the smallest number that can be divided by each of the numbers from  *
* 1 to 10 without any remainder.                                               *
*                                                                              *
* What is the smallest positive number that is evenly divisible by all of the  *
* numbers from 1 to 20?                                                        *
*******************************************************************************/

#include <iostream>

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 1)
    {
        std::cout << "Usage : ./005_smallest_multiple" << std::endl;
        return -1;
    }

    /* Display of results */
    std::cout << "Result of Problem 5 : " << std::endl;

    return 0;
}