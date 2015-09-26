#include<stdio.h>
#include<time.h>

/* ################# opt ::: 1 ::: 18.---
						 ::: 2 :::  9.28
*/
clock_t start, end;
double cpu_time;

typedef enum{true, false} bool;

bool chk_prime(int n)
{
	int q = 0;

	for(int i = n; i >= 1; --i)
	{

		if(n % i == 0)
		{
			++q;
		}
		else 
			continue;
	}

	if(q == 2)
			return true;
		else
			return false;
}

int primo(void)
{
	int i = 1, x = 3;	

	while(i != 10001)
	{
		if(x % 2 != 0 && x % 10 != 0)
		{
			if(chk_prime(x) == true)
			{
				++i;
				++x;

				printf("%d %d\n",i,x-1);
			}
			else{
				++x;
				continue;
			}
		}
		else
		{
			++x;
			continue;
		}
	}

	return x-1;
}

int main()
{
	start = clock();
	int res;

	res = primo();
	printf("\n10001 Prime Number : %d\n",res);
	end = clock();

	cpu_time = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time Taken ::: %f\n", cpu_time);

	return 0;
}