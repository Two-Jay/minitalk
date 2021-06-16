

#include <stdio.h>

int main()
{
	int t = 1 << (sizeof(int) * 8 - 1);

	printf("%d\n", t);
	return (0);
}