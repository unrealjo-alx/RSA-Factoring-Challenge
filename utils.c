#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

/**
 * factorize : parse and factorize given string
 * number into a product of two smaller numbers.
 * @string: The string representation of the number.
 */
void factorize(char *string)
{

	u_int64_t number, i = 2;
	char *end = NULL;

	number = strtoull(string, &end, 10);

	while (i < number / 2 && number % i != 0)
		i++;

	printf("%lu=%lu*%lu\n", number, i, number / i);
}

/**
 * factorize_prime : parse and factorize given string
 * number into a product of two prime numbers.
 * @string: The string representation of the number.
 */
void factorize_prime(char *string)
{

	u_int64_t number, p = 1, q;
	char *end = NULL;

	number = strtoull(string, &end, 10);
	if (is_prime(number))
	{
		printf("%lu=%lu*1\n", number, number);
		return;
	}

	while (p <= number / 2)
	{
		q = number / p;
		/*
		Recheck is necessary here, because in c:
		if number = 3 and p = 2
		then q = 3 / 2 = 1
		as a result p*q = 2 * 1 != number.
		*/
		if (q * p == number && is_prime(q))
		{
			printf("%lu=%lu*%lu\n", number, q, p);
			return;
		}
		p++;
	}
}
/**
 * is_prime : Check wether a number is prime.
 * @num: 64bit unsigned integer number.
 * @return: 1 if number is prime, otherwhere 0.
 */
int is_prime(u_int64_t num)
{
	u_int64_t i;
	if (num <= 1)
		return 0;
	if (num % 2 == 0 && num > 2)
		return 0;
	for (i = 3; i < num / 2; i += 2)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}