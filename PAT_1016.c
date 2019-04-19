#include<stdio.h>
#include<math.h>

int getp(char * A, int DA)
{
	int cou_a = 0, PA = 0;
	for(int i = 0; A[i] ; i++)
		if(A[i] - '0' == DA) PA += DA * pow(10, cou_a++);

	return PA;
}

int main()
{
	char A[12], B[12];
	int DA = 0, DB = 0;

	scanf("%s%d%s%d", A, &DA, B, &DB);
	printf("%d\n", getp(A, DA) + getp(B, DB));

	return 0;
}
