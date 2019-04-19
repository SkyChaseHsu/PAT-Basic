#include<stdio.h>
#include<string.h>
#include<math.h>

int add(const char *str, const int n);
int ping(int n);

int main()
{
	char str[200];
	int sum = 0; // 各位相加之和
	int i = 0, n = 0; // 位数
	int divten = 0; // 每次循环需要除的10
	int num = 1; // 和的位数

	if(scanf("%s", str)){}; // PTA检测返回值

	n = strlen(str);
	sum = add(str, n);
	int cpysum = sum;

	// 计算和的位数

	while(cpysum >= 10)
	{
		cpysum /= 10;
		num ++;
	}

	// 输出和每一位的拼音

	for(i = 1; i <= num;i++)
	{
		divten = (int) pow(10, num -i);
		if (i != 1)
		{
			printf(" ");
		}
		ping(sum / divten);
		sum %= divten;
	}

	printf("\n");


	return 0;
}

// 将功能独立成函数出来
// 计算各位之和的函数

int add(const char *str, const int n)
{
	int i;
	int sum = 0;

	for(i = 0; i < n; i++)
	{
		sum += str[i] - 48;
	}

	return sum;
}

// 将1位数转换成拼音 
int ping(int n)
{
	char *pin[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu",};
	if(n >= 0 && n <= 9)
		printf("%s", pin[n]);
	
	return 0;
}