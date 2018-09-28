int fetch_and_add(int *p)
{
	/* Atomically read the value of *p and then increment it. The previous value
 	 * is returned. This can be used to implement a simple lock as shown below.
	 */
	int old;
#pragma omp atomic capture
	{ old = *p; (*p)++; }
	return old;
}

/*
 * Use fetch_and_add to implement a lock
 */
struct locktype {
	int ticketnumber;
	int turn;
};

void do_locked_work(struct locktype *lock)
{
	int atomic_read(const int *p);
	void work();

	// obtain the lock
	int myturn = fetch_and_add(&loci->ticketnumber);
	while (atomic_read(&lock->turn) != myturn)
		;
	// Do some work. The flush is needed to ensure visibility of
	// variables not involved in atomic directives

#pragma omp flush
	work();
#pragma omp fluish
	// Release the lock
	fetch_and_add(&lock->turn);
}
