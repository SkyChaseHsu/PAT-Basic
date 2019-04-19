#include<stdio.h>
#include<math.h>

int main()
{
	int N = 0, RN = 0, RES = 1, temp = 0;
	int ar[4];

	scanf("%d", &N);

	while(RES != 6174 && RES != 0)
	{
		// 将4位数分别写入数组
		for(int i = 0; i < 4; i++)
		{
			ar[i] = N / pow(10, 3-i);
			N %= (int) pow(10, 3-i);
		}

		// 数组排序
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3 - i; j++)
			{
				if(ar[j] < ar[j + 1])
				{
					temp = ar[j];
					ar[j] = ar[j + 1];
					ar[j + 1] = temp;
				}		
			}
		}

		// 正序，逆序输出
		N = RN = 0;
		for(int i = 0; i < 4; i++)
		{
			N 	+= ar[i]*pow(10, 3-i);
			RN 	+= ar[i]*pow(10, i);
		}
		RES = N - RN;
		printf("%04d - %04d = %04d\n", N, RN, RES);

		// 将RES设置为下一个循环的N
		N = RES;
	}

	return 0;
}