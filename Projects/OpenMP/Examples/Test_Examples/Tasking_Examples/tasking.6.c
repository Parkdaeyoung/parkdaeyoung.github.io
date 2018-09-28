#define LARGE_NUMBER 10000000
double item[LARGE_NUMBER];
extern void process(double);

int main()
{
#pragma omp parallel
	{
#pragma omp single
		{
			int i;
#pragma omp task unitied
			{
				for (i = 0; i < LARGE_NUMBER; i++)
#pragma omp task
					process(item[i]);
			}
		}
	}
	return 0;
}
