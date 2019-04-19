#include<stdio.h>

int main(){
	// int cnt = 1;
	int num;
	int i;

	if(scanf("%d", &num)){};

	// 本来想用这个算出位数
	// for(cnt = 1; cnt <= num; cnt *= 10){};
	// cnt /= 10;

    if(num/100){
    	for(i = 1; i <= num/100;i++)
    		printf("B");

    	num %= 100;
    }

    if(num/10){
    	for(i = 1; i <= num/10;i++)
    		printf("S");

    	num %= 10;
    }

    if(num){
    	for(i = 1; i <= num; i++)
    		printf("%d", i);
    }

    printf("\n");


}