#include "main.h"
/**
 * isPrime - Checks if a number is prime
 * @n: number given
 * @div: Divisor
 *
 * Return: 1 if prime 0 otherwise
 */
int isPrime(int n, int div)
{
	if (n <= 1)
	{
		return (0);
	}
	if (div == 1)
	{
		return (1);
	}
	if (n % div == 0)
	{
		return (0);
	}
	else
	{
		return (isPrime(n, div - 1));
	}
}
/**
 * is_prime_number - Checks for prime numbers
 * @n: number passed
 *
 * Return: 1 if prime 0 otherwise
 */
int is_prime_number(int n)
{
	return (isPrime(n, n - 1));
}
