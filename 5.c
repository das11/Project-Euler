#include<stdio.h>
#include<time.h>

typedef enum {true, false} bool;


clock_t start, end;
double cpu_time;

bool factoid(int n)
{
	for(int i = 1; i <= 20; ++i)
	{
		if(n % i == 0)
			continue;
		else
			return false;
	}

	return true;
}

bool evenify(int n)
{
	if(((n % 5) == 0) || ((n % 2) == 0))
		return true;
	else 
		return false;
}

int main()
{
	start = clock();

	unsigned int i = 20,res;

	while(2)
	{
		if(evenify(i) == true)
		{
			if(factoid(i) == true)
			{
				res = i;
				printf("%d\n",i);
				break;
			}
			else
			{
				++i;
				continue;
			}
		}
		else
		{ 
			++i;
			continue;
		}

		
	}
	printf("\n%d\n",res);

	end = clock();
	cpu_time = (double)((end - start))/CLOCKS_PER_SEC;

	printf("Time taken ::: %f\n", cpu_time);

	return 0;
}