#include<stdio.h>
#include<time.h>

#define START 100
#define END 999
typedef enum {true, false} bool;


clock_t start, end;
double cpu_time;

int count(int n)				//Returns the number of digits of a number
{
	int tag = 0;
	while(n != 0)
	{
		n /= 10;
		++tag;
	}

	return tag;
}

bool chk_palin(int x)			//Checks if Palindrome
{

	int rev = 0,mul = 1,_tag, temp = x;	//"mul" - multiplies that inflates the "rev" to accumulate

	//scanf("%d", &x);

	_tag = count(x);

	for(int i = 1; i < _tag; ++i)
		mul *= 10;
	
	while(temp != 0)
	{
		rev += mul * (temp % 10);
		mul /= 10;
		temp /= 10;
	}

	//printf("\n%d\n",rev);
	//printf("%d\n",x);

	if(x == rev)
		return true;
	else
		return false;
}

void swap(int *p, int *q)		// Swaps
{
	*p = *p + *q;
	*q = *p - *q;
	*p = *p - *q;
}

int get_l(int x[], int n) //Using Insertion Sort ### Returns lagest in an array
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if(x[j] < x[i])
			{
				swap(&x[i],&x[j]);
			}
		}
	}

	return x[n-1];
}

int *get_factors(int x) // Returns factors
{
	static int a[2];
	for(int i = START; i < END; ++i)
		for(int j = START; j < END; ++j)
		{
			if(i*j == x)
			{
				a[0] = i;
				a[1] = j;
			}
			else
				continue;
		}
		return a;
}

void get_palin(void)	// Gets Palins and Prints result
{
	unsigned int max = 1000 * 1000;
	unsigned int temp[max];
	int k = 0, l = 0, pal[max];
	int res;

	for(int i = START; i <= END; ++i)
		for(int j = START; j <= END; ++j)
		{
			temp[k] = i * j;
			if(chk_palin(temp[k]) == true)
			{
				pal[l] = temp[k];
				++l;
			}
			else 
				continue;
			++k;
		}

		res = get_l(pal,k);
		int *f = get_factors(res);
		printf("\nLargest Palindrome product of two (2) 3 digit numbers --> %d \nWhose factors are --> %d %d \n\n", res, *f, *(f+1));

		//for (int i = 0; i < k; ++i)
		//	printf("\n%d\n", pal[i]);
		
}

int main()
{
	start = clock();

	get_palin();
	
	end = clock();
	cpu_time = (double)((end - start))		/CLOCKS_PER_SEC;
	printf("Time taken : %f s\n", cpu_time);

	return 0;
}




