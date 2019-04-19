#include<stdio.h>
#include<string.h>

char max(int B, int J, int C)
{
	char max;
	if(J >= B && J >= C) max = 'J';
	if(C >= B && C >= J) max = 'C';
	if(B >= J && B >= C) max = 'B';
	return max;
}

int main()
{
	int N = 0, tie = 0;
	int Jwin = 0, JwinB = 0, JwinJ = 0, JwinC = 0;
	int Ywin = 0, YwinB = 0, YwinJ = 0, YwinC = 0;
	char line[5];
	scanf("%d", &N);

	while(getchar() != '\n');
	for(int i = 0; i < N; i++)
	{
		fgets(line, 5, stdin);
		line[strlen(line) - 1] = '\0';
		if(!strcmp(line, "B C")) JwinB++;
		if(!strcmp(line, "J B")) JwinJ++;
		if(!strcmp(line, "C J")) JwinC++;
		if(!strcmp(line, "C B")) YwinB++;
		if(!strcmp(line, "B J")) YwinJ++;
		if(!strcmp(line, "J C")) YwinC++;
	}

	Jwin = JwinB + JwinJ + JwinC;
	Ywin = YwinB + YwinJ + YwinC;
	tie = N - Jwin - Ywin;

	printf("%d %d %d\n%d %d %d\n", 
			Jwin, tie, Ywin, Ywin, tie, Jwin);

	printf("%c %c\n", 
			max(JwinB, JwinJ, JwinC), max(YwinB, YwinJ, YwinC));

	return 0;
}


