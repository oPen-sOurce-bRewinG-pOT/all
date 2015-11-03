#include <omp.h>
#include <stdio.h>
main()
{
	omp_lock_t lck;
	omp_init_lock(&lck);
	int id, tmp;
        #pragma omp parallel num_threads(1000) private(tmp,id)
        {
                id=omp_get_thread_num();
                tmp=id*id;
		omp_set_lock(&lck);
                printf("%d ",id);
                printf("%d\n",tmp);
		omp_unset_lock(&lck);
        }
	omp_destroy_lock(&lck);
}
