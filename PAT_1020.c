#include<stdio.h>
#include<stdlib.h>

typedef struct _Product
{
	double sto;
	double pri;
	double uni;
}Product;

int cmp( const void *a ,const void *b)
{
return (*(Product *)a).uni < (*(Product *)b).uni ? 1 : -1;
}

int main(int argc, char const *argv[])
{
	int N = 0, D = 0, cnt = 0;
	double income = 0.0;

	// 输入数据
	scanf("%d %d", &N, &D);
	Product pro[N];
	for(int i = 0; i < N; i++)
		scanf("%lf", &pro[i].sto);
 	for(int i = 0; i < N; i++)
 	{
 		scanf("%lf", &pro[i].pri);
 		pro[i].uni = pro[i].pri / pro[i].sto;
 	}

 	// 排序，单价从高到低
 	qsort(pro, N, sizeof(Product), cmp);

	// 计算最大收益
	if(D == 0) {printf("%d\n", D);}
	else{
		 double res = 0;
		 int i = 0;
		 for(i = 0; i < N; i++)
		 {
			if(D >= pro[i].sto)
			{
				res += pro[i].sto;
				D 	-= pro[i].sto;
				pro[i].sto = 0;
				income += pro[i].pri;
			}else{
				break;
			}
		 }
		 if(D >= 0)
		 {
			 income += D * pro[i].uni;
		 };
		printf("%.2lf\n", income);
	}
	return 0;
}