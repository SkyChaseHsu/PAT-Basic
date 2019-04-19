#include<stdio.h>

int main()
{
	char A[1001];
	int B = 0, remainder = 0, carrybit = 0;
	scanf("%s%d", A, &B);


	for(int i = 0; A[i]; i++)
	{
		carrybit = remainder * 10 + A[i] - '0';
		A[i] = carrybit / B + '0';
		remainder = carrybit % B;
	}

	// 1. *p++ == '0' 为了除掉前面的0
	// 2. *p 防止结果就是 0 这种情况
	char *p = A;
	while( *p++ == '0' && *p);

	printf("%s %d\n", p-1, remainder);

	return 0;
}
