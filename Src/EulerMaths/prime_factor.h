/*******************************************************************************
* Header file containing all functions related to prime numbers.               *
*******************************************************************************/

#include "eulermaths.h"

std::vector<bool> sieveOfEratosthenes(int n);
std::vector<bool> sieveOfSundaram(int n);
bool isPrimeFactor(int n);
std::map<int,int> primeFactorDecomposition(int value);