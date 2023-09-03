#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "factors.h"

/**
 * main - Reads numbers from a given file and
 * factorize each numuber into a product of two smaller numbers.
 */
int main(int argc, char const *argv[])
{
	FILE *file;
	char *buffer = NULL;
	size_t length = 0;

	if (argc < 2)
		exit(EXIT_FAILURE);

	file = fopen(argv[1], "r");
	if (file == NULL)
		exit(EXIT_FAILURE);

	srand(time(0));
	while (getline(&buffer, &length, file) != -1)
		factorize(buffer);

	fclose(file);
	free(buffer);
	return 0;
}

void factorize(char *string)
{
	u_int64_t random, number;
	char *end = NULL;
	number = strtoull(string, &end, 10);
	do
	{
		random = rand() % (u_int64_t)(sqrtl(number)) + 2;
	} while (number % random != 0);
	printf("%llu=%llux%llu\n", number, random, number / random);
}