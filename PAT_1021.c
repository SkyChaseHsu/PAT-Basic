#include<stdio.h>
#include<string.h>

int main()
{
	char N[1002];
    int n[10] = {0}, i = 0;

	fgets(N, 10002, stdin);
	N[strlen(N) - 1] = '\0';

    while(N[i])
        n[N[i++] - '0']++;

    for(i = 0; i <= 9; i++)
        if(n[i]) printf("%d:%d\n", i, n[i]);

	return 0;
}