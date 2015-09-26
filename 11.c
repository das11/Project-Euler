#include<stdio.h>
//#include<stdlib.h>
#include<time.h>

/*
		---------------------------------------->   y - axis
	  	|
		|	00 01 02 03 04 
		|	10 11 12 13 14		#### Sample indices
		|	20 21 22 23 24
		|	30 31 32 33 34
		|
		V

	   x - axis

*/

extern int errno;
int x[20][20]; 
clock_t start, end;
double cpu_time;

void stream(void)
{
	FILE *f;
	f = fopen("/Users/Interface/ii.txt", "r");
	
	if(f == NULL)
	{
		fprintf(stderr,"\nFailed to read file %d\n", errno);
	}
	else
	{
		for(int i = 0; i < 20; ++i)
			for(int j = 0; j < 20; ++j)
			{
				fscanf(f, "%d", &x[i][j]);
			}
			printf("\n");
	}
	
	fclose(f);

	for(int i = 0; i < 20; ++i)
	{
		for(int j = 0; j < 20; ++j)
		{
			printf(" %2d ",x[i][j]);
		}
		printf("\n");
	}
}


void swap(unsigned int *a, unsigned int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void sort(unsigned int ar[], int n)
{
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
		{
			if(ar[j] < ar[i])
			{
				swap(&ar[i], &ar[j]);
			}
		}
}

int dl_diagonal(void)
{
	int k = 0;
	unsigned sum[290];

	for(int _x = 3; _x < 20; ++_x)
		for(int _y = 3; _y < 20; ++_y)
		{
			sum[k] = x[_x][_y] * x[_x+1][_y-1] * x[_x+2][_y-2] * x[_x+3][_y-3];
			++k;
		}

	sort(sum,290);

	return sum[289];
}

int d_diagonal(void)
{
	int k = 0;
	unsigned sum[290];

	for(int x_ = 0; x_ < 17; ++x_)
		for(int y_ = 0; y_ < 17; ++y_)
		{

			sum[k] = x[x_][y_] * x[x_+1][y_+1] * 
					 x[x_+2][y_+2] * x[x_+3][y_+3];
			++k;

		}

	sort(sum, 290);

	/*for(int i = 0; i < 305; ++i)
		printf("%d\n",sum[i]);*/

	return sum[289];
}

int down(void)
{
	int k = 0; 
	unsigned int sum[341];

	for(int x_ = 0; x_ < 17; ++x_)
		for(int _y = 0; _y < 20; ++_y)
		{
			sum[k] = x[x_][_y] * x[x_+1][_y] * x[x_+2][_y] * x[x_+3][_y];
			++k;
		}

	sort(sum, 341);

	return sum[340];
}

int up(void)
{
	int k = 0;
	unsigned int sum[341];

	for(int _x = 3; _x < 20; ++_x)
		for(int _y = 0; _y < 20; ++_y)
		{
			sum[k] = x[_x][_y] * x[_x-1][_y] * x[_x-2][_y] * x[_x-3][_y];
			++k;
		}
	sort(sum, 341);

	return sum[340];
}

int right(void)
{
	int k = 0; 
	unsigned int sum[341];

	for(int _x = 0; _x < 20; ++_x)
		for(int _y = 0; _y < 17; ++_y)
		{
			sum[k] = x[_x][_y] * x[_x][_y+1] * x[_x][_y+2] * x[_x][_y+3];
			++k;
		}

	sort(sum, 341);

	return sum[340];
}

int left(void)
{
	int k = 0;
	unsigned int sum[341];

	for(int _x = 3; _x < 20; ++_x)
		for(int _y = 0; _y < 20; ++_y)
		{
			sum[k] = x[_x][_y] * x[_x][_y-1] * x[_x][_y-2] * x[_x][_y-3];
			++k;
		}

	sort(sum, 341);

	return sum[340];
}



int main()
{
	start = clock();

	unsigned int q[6];
	stream();

	q[0] = d_diagonal();
    q[1] = up();
 	q[2] = down();
	q[3] = right();
	q[4] = left();
	q[5] = dl_diagonal();

	sort(q, 6);
	printf("\n\nLargest Product (after ravaging the matrix) :: %u\n", q[5]);
	end = clock();

	cpu_time = (double)(end - start)/CLOCKS_PER_SEC;
	printf("\nTime taken ::: %f\n\n", cpu_time);


	return 0;
}	