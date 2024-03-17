#include <stdio.h>

int main() {
	int n1, n2;
	char c;

	scanf("%d ", &n1);
	c = getchar();
	scanf("%d", &n2);
	
	switch (c) {
	case '+':
		printf("%d", n1 + n2);
		break;
	case '-':
		printf("%d", n1 - n2);
		break;
	case '/':
		printf("%.2f", (float)n1 / n2);
		break;
	case '*':
		printf("%d", n1 * n2);
	}

	return 0;
}