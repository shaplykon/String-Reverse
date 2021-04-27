#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include <sys/stat.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAXCHAR 100

int main(int argc, char** argv)
{
	char inputFilename[MAXCHAR];
	char outputFilename[MAXCHAR];
	char line[MAXCHAR];

	if (argc == 1)
	{
		printf("%s", "Pass input file path as argument!");
		return 1;
	}
	else if (argc == 2)
	{
		strcpy(inputFilename, argv[1]);
		strcpy(outputFilename, "result.txt");
		printf("%s\n", "Result will be written in default file \"result.txt\"");
	}
	else if (argc == 3)
	{
		strcpy(inputFilename, argv[1]);
		strcpy(outputFilename, argv[2]);

	}

	FILE* inputFile = fopen(inputFilename, "r");
	FILE* outputFile = fopen(outputFilename, "w");

	if (inputFile == NULL) {
		printf("Could not open file %s", inputFilename);
		return 1;
	}

	if (outputFile == NULL)
	{
		printf("Error opening output file!\n");
		return 1;
	}

	while (fgets(line, MAXCHAR, inputFile) != NULL)
	{
		reverse(line, 0, strlen(line) - 1);
		fprintf(outputFile, "%s", line);
	}

	struct stat buffer;

	if (stat(outputFilename, &buffer) == 0) {
		printf("Text from %s was reversed and successfully written in %s file!", inputFilename, outputFilename);
	}
	else {
		printf("Errors occured during string reverse from file %s", inputFilename);
	}

	fclose(inputFile);
	fclose(outputFile);
}