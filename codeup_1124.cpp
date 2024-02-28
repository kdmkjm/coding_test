#include <stdio.h>

int main()
{
	int a, b, c;
	c = scanf("C%dH%d", &a, &b);

	printf("%d", 12 * a + b);

	return 0;
}