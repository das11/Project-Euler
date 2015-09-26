#include<stdio.h>
#include<time.h>
#include<math.h>

//typedef enum{true,false} bool;

clock_t start, end;
double cpu_time;


void soe(int n)
{
	
	int x[n], c = 0;
	unsigned long long int sum = 2;

	for(int i = 0; i < n; ++i)
		x[i] = 0;

	for(int i = 3; i < n; i += 2)
	{
		x[c] = i;
		//printf("%d   %d\n", x[c], c);
		++c;
	}

	for(int i = 0; x[i] <= sqrt(n); ++i)
		for(int j = i + 1; j < n; ++j)
		{
			if(x[j] % x[i] == 0)
			{
				x[j] = -12;
			}
			else
				continue;
		}

	for(int i = 0; i < n; ++i)
	{
		if(x[i] != -12)
		{
			//printf("\n%d   : %d\n",x[i],i);
			sum += x[i];
		}
		else
			continue;
	}

	printf("\nSum 0f primes < %d --> %llu\n",n,sum );
}

int main()
{
	start = clock();
	soe(2000000);
	end = clock();

	cpu_time = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time Taken :::%f\n",cpu_time);
	return 0;

}