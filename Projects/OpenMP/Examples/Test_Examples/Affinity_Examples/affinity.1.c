void work();
int main()
{
#pragma omp parallel proc_bind(spread) num_threads(4)
	{
		work();
	}
}
