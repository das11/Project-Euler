#include<stdio.h>
#include<time.h>

clock_t start, end;
double cpu_time;

int s_sq(void)
{
	int res = 0;
	for(int i = 1; i <= 100; ++i)
	{
		res += (i * i);
	}

	return res;
}

int sq_s(void)
{
	int res = 0;
	for(int i = 1; i <= 100; ++i)
	{
		res += i;
	}

	return (res*res);
}

int main()
{
	start = clock();
	int sum, sum_sq,res;

	sum = sq_s();
	sum_sq = s_sq();
	res = sum - sum_sq;

	printf("\n%d\n",res);
	
	end = clock();
	cpu_time = (double)(end - start)/CLOCKS_PER_SEC;

	printf("Time taken ::: %f\n\n", cpu_time);

	return 0;
}