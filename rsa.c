#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/**
 * main - The program's entry point that takes a file as argument.
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

	while (getline(&buffer, &length, file) != -1)
		factorize_prime(buffer);

	fclose(file);
	free(buffer);
	return 0;
}