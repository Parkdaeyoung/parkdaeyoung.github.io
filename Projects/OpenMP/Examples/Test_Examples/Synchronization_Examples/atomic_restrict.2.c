void atomic_wrong2()
{
	int x;
	int *i;
	float *r;

	i = &x;
	r = (float *)&x;

#pragma omp parallel
	{
#pragma omp atomic update
		*i += 1;

#pragma omp atomic update
		*r += 1.0;

		/* Incorrect because the atomic constructs reference the smae location
 		 * through incompatible types */
	}
}
