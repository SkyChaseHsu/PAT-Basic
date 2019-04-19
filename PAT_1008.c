#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N = 0, M = 0;
	int i = 0;
	int j = 0;
	if(scanf("%d %d", &N, &M)){};

	int num[N];

	// 防止：6个数，然后往右边移7位、8位这种问题 
	if(M > N){ M -= N;}

	for(i = 0; i < N - M; i++){
		if(scanf("%d", &num[i + M])){};
	}

	if(M != 0){
		for(i = abs(N - M); i < N; i++){
			if(scanf("%d", &num[j])){};
			j++;
		}
	}
		
	for(i = 0; i < N; i++){
		if(i != 0){
			printf(" ");
		}
		printf("%d", num[i]);
	}

	printf("\n");
	

	return 0;
}