#include<stdio.h>

int isPrime(long long num);

int main(){
	long long N;
	long long cnt = 0;
	long long temp[2] = {-1,-1};
	long long i = 0;

	if(scanf("%lld", &N)){};

	for(i = 2; i <= N; i++)
	{
		// 每算出一个数都和上一个进行对比
		temp[1] = temp[0];
		if(isPrime(i))
			temp[0] = i;
		if(temp[0] - temp[1] == 2)
			cnt++;
	}

	printf("%lld\n", cnt);

	return 0;
}

int isPrime(long long num)
{
	long long i;
	int ret = 1;
	for(i = 2; i * i <= num; i++){
		if(num % i == 0){
			ret = 0;
			break;
		}
	}

	return ret;
}

