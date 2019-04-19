#include<stdio.h>
#include<math.h>

int main()
{
	int A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0;
	int N, n = 0;
	int i2 = 0, i4 = 0;

	if(scanf("%d", &N)){};

	while(N--)
	{
		if(scanf("%d", &n)){};
		switch(n % 5){
			case 0:  	A1 += n % 2 ? 0 : n;			break;
			case 1:		A2 += pow(-1, i2++) * n;		break;
			case 2:		A3 ++;							break;
			case 3: 	A4 += n; i4++;					break;
			default: 	A5 = n > A5? n : A5;			break;
		}
	}

	if(A1) printf("%d", A1); 				else printf("N");
	if(i2) printf(" %d", A2); 				else printf(" N");
	if(A3) printf(" %d", A3); 				else printf(" N");
	if(A4) printf(" %.1f", A4 * 1.0 / i4); 	else printf(" N");
	if(A5) printf(" %d", A5);  				else printf(" N");

	printf("\n");

	return 0;
}