#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include <unistd.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAXCHAR 1000
void reverse(char* x, int begin, int end);

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
		if (line != ""){
			fprintf(outputFile, "%s\n", line);
		}
		//strrev(line);

	}

	fclose(inputFile);
	fclose(outputFile);
}

void reverse(char* x, int begin, int end)
{
	char c;

	if (begin >= end)
		return;

	c = *(x + begin);
	*(x + begin) = *(x + end);
	*(x + end) = c;

	reverse(x, ++begin, --end);
}