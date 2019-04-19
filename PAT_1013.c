#include<stdio.h>

int isPrime(int num);

int main()
{
	int M = 0, N = 0;

	int cnt_p = 0;

	if(scanf("%d %d", &M, &N)){};

	for(int i = 2; cnt_p < N; i ++)
	{
		if(isPrime(i))
		{
			cnt_p ++;
			if(cnt_p >= M)
			{
				if( (cnt_p - M) % 10 == 0) {
					if(cnt_p - M != 0) printf("\n");
				}
				else {
					printf(" ");
				}
				printf("%d", i);				
			}
		}
	}

	printf("\n");

	return 0;
}

int isPrime(int num)
{
	int ret = 1;
	for(int i = 2; i * i <= num; i++)
	{
		if(num % i == 0) 
		{
			ret = 0; 
			ret = 0; 
			break;
		}	
	} 	
	return ret;
}