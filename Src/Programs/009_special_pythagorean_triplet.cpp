/*******************************************************************************
* Problem 9 : Special Pythagorean triplet                                      *
*                                                                              *
* A Pythagorean triplet is a set of three natural numbers, a < b < c,          *
* for which,                                                                   *
*                  a² + b² = c²                                                *
*                                                                              *
* For example, 3² + 4² = 9 + 16 = 25 = 5².                                     *
*                                                                              *
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.     *
* Find the product abc.                                                        *
*******************************************************************************/

#include <eulermaths.h>

int main (int argc, char *argv[])
{
    /* Input processing */
    if (argc != 1)
    {
        std::cerr << "Usage : ./009_special_pythagorean_triplet" << std::endl;
        return -1;
    }

    int a, b, c;
    c = 335;
    b = 334;
    a = 1000 - b - c;

    while ((a + b + c != 1000) || (pow(a,2) + pow(b,2) != pow(c,2)))
    {
        if (a > b || b == 2)
        {
            c += 1;
            b = c - 1;
        }
        b -= 1;
        a = 1000 - c - b;
    }

    int product = a*b*c;

    /* Display of results */
    std::cout << "The product abc for which a + b + c = 1000 is ";
    std::cout << a << " * " << b << " * " << c << " = " << product << std::endl;

    return 0;
}