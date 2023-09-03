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

	u_int64_t sqrt_number, number, i = 2;
	char *end = NULL;

	number = strtoull(string, &end, 10);
	sqrt_number = (u_int64_t)sqrtl(number);

	while (i < sqrt_number && number % i != 0)
		i++;

	printf("%llu=%llu*%llu\n", number, i, number / i);
}