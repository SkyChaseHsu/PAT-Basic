#include<stdio.h>
#include<stdbool.h>

int odd(int num);

int main()
{
	// 记录哪些数字被cover了
	bool cover[101];

	// 正整数的个数
	int k = 0;

	// 用于计数的数
	int i = 0, j = 0;

	// 读入正整数的个数
	if(scanf("%d", &k)){};

	// 存放正整数的数组
	int num[k];
	// 存放关键数字
	int keys[k];

	// 逐个读入正整数
	for(i = 0; i < k; i++)
	{
		if(scanf("%d", &num[i])){};	 
	}

	// 初始化cover表
	cover[0] = 1;
	for(i = 1; i <= 100; i++)
		cover[i] = 0;

	// 将输出的结果覆盖到cover表上
	int t_num = 0;
	for(i = 0;i < k ;i++){

		t_num = num[i];

		while(t_num != 1){
			if(odd(t_num))
				t_num = (3 * t_num + 1) / 2;
			else
				t_num /= 2;

			// 一定要做这个检测，比如(99*3 + 1)/2 = 149
			// 一下子就超出这个检测范围了，就会出现段错误
			if(t_num >= 1 && t_num <= 100)
				cover[t_num] = 1;
		} 
	}

	// 将没有被cover的数存在keys表里，已经在上面初始化j=0
	for(i = 0; i < k; i++)
	{
		if(cover[num[i]] == 0){
			keys[j] = num[i];
			j++;
		}
	}

	// 排序算法
	int l = j;
	int temp = 0;

	for (i = 0; i <= l; i++) {
        for (j = i + 1; j <= l-1; j++)
            if (keys[i] < keys[j]) {
                temp = keys[i];
                keys[i] = keys[j];
                keys[j] = temp;
            }
    }

	// 输出keys数组
	for(i = 0; i < l; i++){
		if(i != 0){
			printf(" ");
		}	
		printf("%d", keys[i]);
	}
	printf("\n");

	return 0;
}


// 判断是否是奇数
int odd(int num)
{
	int ret = 1;
	if(num % 2 == 0)
		ret = 0;
	return ret;
}







