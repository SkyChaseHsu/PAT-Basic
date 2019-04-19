#include<stdio.h>
#include<ctype.h>

int main()
{
	char s1[61], s2[61], s3[61], s4[61];
	scanf("%s %s %s %s", s1, s2, s3, s4);

	// 输出约会是星期几
	char * week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int DAY = 0;
	int i = 0;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if(s1[i] == s2[i] && s1[i] >= 'A' && s2[i] <= 'G') break;
	}

	DAY = s1[i] - 'A';
	printf("%s ", week[DAY]);

	// 输出约会的时
	int HH = 0;
	int j = 0;

	for(j = i + 1; s1[j] && s2[j]; j++)
	{
		if(s1[j] == s2[j])
		{
			if(s1[j] >= 'A' && s1[j] <= 'N')
			{
				HH = s1[j] - 'A' + 10;
				break;
			}
			if(isdigit(s1[j]))
			{
				HH = s1[j] - '0';
				break;
			}
		}				
	}

	printf("%02d:", HH);

	// 输出约会的秒
	int MM = 0;
	int k = 0;

	for(k = 0; s3[k] && s4[k]; k++)
	{
		if(s3[k] == s4[k] && isalpha(s3[k])) break;
	}

	MM = k;
	printf("%02d\n", MM);

	return 0;
}

// 检验字符串结尾的套路 if(str[i]) 之前用的是if(str[i] != '\0')
// 检验数字 isdigit(), 检验字母 isalpha()
// 阅读能力差 ，一开始做错了好几次
