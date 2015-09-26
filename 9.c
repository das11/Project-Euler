#include<stdio.h>
#include<time.h>

clock_t start, end;
double cpu_time;
/*
void point(int x[], int y[], int z[])
{
	for(int i = 0; i < 82834; ++i)
	{
		if((z[i]*z[i]) == ((y[i]*y[i]) + (z[i]*z[i])))
		{
			printf(" ::::: %d >> %d >> %d >> \n", x[i], y[i], z[i]);
		}
		//printf("\n%d %d %d",x[i],y[i],z[i]);
	}	
}

void equify(void)
{
	
	unsigned int index = 0;
	int x[83000],y[83000],z[83000];

	for(int i = 1; i <= 1000; ++i)
		for(int j = i + 1; j <= 1000; ++j)
			for(int k = j + 1; k <= 1000; ++k)
			{
				if((i + j + k) == 1000)
				{
					x[index] = i;
					y[index] = j;
					z[index] = k;

					printf("\nx[%d] :: %d y[%d] :: %d z[%d] :: %d >>>>>>>>%d\n",index,i,index,j,index,k,index);
					
					++index;
				}
				else 
					continue;
			}
	point(x,y,z);
	
}
*/

void trip_equify(int n)
{
	for(int i = 1; i < n; i++)
		for(int j = 2; j < i; j++)
		{
			if((i*i) + (j*j) == (n - i - j)*(n - i - j))
			{
				printf("\nTriplet Prod :: %d\n", i*j*(n-i-j));
			}
		}
}

int main()
{
	//equify();
	start = clock();
	trip_equify(1000);
	end = clock();

	cpu_time = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time Taken ::: %f\n",cpu_time);

	return 0;
}
