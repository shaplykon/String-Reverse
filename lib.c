#include "lib.h"
#include <string.h>

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