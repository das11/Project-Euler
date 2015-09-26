#include<stdio.h>
#include<time.h>

clock_t start,end;
double cpu_time;
			
double tst(int x[], int n)			//Actually multiplies !!
{
	double res = 1;
	for(int i = n; i < (n+13); ++i)
	{
		res *= x[i];
		//printf("%d   %d\n",i,x[i]);
	}

	return res;
}

void swap(double *p, double *q)
{
	/*
	*p = *p + *q;
	*q = *p - *q;
	*p = *p - *q;
	*/
	double temp = *p;
	*p = *q;
	*q = temp;
}

void tin(double x[])	// Test Insertion Sort
{
	for(int i = 0; i < 1000; ++i)
		for(int j = i + 1; j < 1000; ++j)
		{
			if(x[j] < x[i]){
				swap(&x[i], &x[j]);
			}
		}
}

double get_l(double x[])
{
	for(int i = 0; i < 1000; ++i)
		for(int j = i + 1; j < 1000; ++j)
		{
			if(x[j] < x[i]){
				swap(&x[i], &x[j]);
			}
		}
	return x[999];
}

void inflate(void)
{
	char str[1000] = {"7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"};

	double res[1000], res2;	//The final array containing prod of successive 13's
	int x[1000];

	for(int i = 0; i < 1000; ++i)
	{
		x[i] = str[i] - '0';
		//printf("%d ",x[i]);
	}
	
	for(int i = 0; i < 1000; ++i)
	{
		res[i] = tst(x,i);
		//printf("%f\n", res[i]);
	}

	//printf("\n\n\n%f \n", res[991]);
	//tin(res);

	res2 = get_l(res);

	for(int i = 0; i <1000; ++i)
	{
		printf(">>>%d  ||  %f\n", i,res[i]);
	}

	printf("\n::::::: %f         >> Damn Large Prod. of 13 adjacent digits\n",res2);


}

int main()
{
	start = clock();
	inflate();
	end = clock();

	cpu_time = (double)(end - start)/CLOCKS_PER_SEC;
	printf("\nTime Taken :: %f\n",cpu_time);

	return 0;
}