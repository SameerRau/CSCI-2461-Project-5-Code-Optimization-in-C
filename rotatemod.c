/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* the getUserTime function is used for measurement, you should not change the code for this function */

long int getUserTime()
{
    int who= RUSAGE_SELF;
    int ret;
    struct rusage usage;
    struct rusage *p=&usage;
    //long int current_time;
    
    ret=getrusage(who,p);
    if(ret == -1)
    {
        printf("Could not get GETRUSAGE to work in function %s at line %d in file %s\n",
               __PRETTY_FUNCTION__, __LINE__, __FILE__);
        exit(1);
    }
    return (p->ru_utime.tv_sec * 1000000 + p->ru_utime.tv_usec);
}

/*
 * naive_rotate - The naive baseline version of rotate
 */
/* The parameters, pointers, rusage_time, rdtsc_time, and cpu_time_used are used to measure performance and return values to caller. */
/* You should not change the code that uses these parameters and variables. */

char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst, int *rusage_time, unsigned long long *rdtsc_time)
{
    int i, j;
    /* the variables below are used for performance measurement and not for computing the results of the algorithm */
    long int rusage_start_time, rusage_end_time = 0;
    unsigned long long rdtsc_start_time, rdtsc_end_time = 0;
    /* call system functions to start measuring performance. you should not bother to change these. */
    
    rusage_start_time = getUserTime();
    rdtsc_start_time = rdtsc();
    
    /* below is the main computations for the rotate function */
    
    for (j = 0; j < dim; j++)
        for (i = 0; i < dim; i++)
            dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
    
    /* the remaining lines in this function stop the measurement and set the values before returning. */
    
    rusage_end_time = getUserTime();
    rdtsc_end_time = rdtsc();
    
    *rusage_time = rusage_end_time - rusage_start_time;
    *rdtsc_time = rdtsc_end_time - rdtsc_start_time;
}

/* The parameters, pointers, rusage_time, rdtsc_time, and cpu_time_used are used to measure performance and return values to caller. */
/* You should not change the code that uses these parameters and variables. */
char my_rotate_descr[] = "my_rotate: Naive baseline implementation";
void my_rotate(int dim, pixel *src, pixel *dst, int *rusage_time, unsigned long long *rdtsc_time)
{
    
    /* the variables below are used for performance measurement and not for computing the results of the algorithm */
    long int rusage_start_time, rusage_end_time = 0;
    unsigned long long rdtsc_start_time, rdtsc_end_time = 0;
    /* call system functions to start measuring performance. you should not bother to change these. */
    rusage_start_time = getUserTime();
    rdtsc_start_time = rdtsc();
    
    /* ANY CHANGES ARE MADE HERE */
    /* below are the main computations for your implementation of the rotate. Any changes in implementation will go here or the other functions it may call */
    int size = dim * dim - dim;
    
    int i, k, j, num;
    
    for (k=0; k < dim; k+=32){
        for ( j = 0 ; j < dim; j++){
            num = size - j * dim;
            i = k * dim + j;
            dst[num + k] = src[i];
            dst[num + (k+1)] = src [i +=dim];
            dst[num + (k+2)] = src [i +=dim];
            dst[num + (k+3)] = src [i +=dim];
            dst[num + (k+4)] = src [i +=dim];
            dst[num + (k+5)] = src [i +=dim];
            dst[num + (k+6)] = src [i +=dim];
            dst[num + (k+7)] = src [i +=dim];
            dst[num + (k+8)] = src [i +=dim];
            dst[num + (k+9)] = src [i +=dim];
            dst[num + (k+10)] = src [i +=dim];
            dst[num + (k+11)] = src [i +=dim];
            dst[num + (k+12)] = src [i +=dim];
            dst[num + (k+13)] = src [i +=dim];
            dst[num + (k+14)] = src [i +=dim];
            dst[num + (k+15)] = src [i +=dim];
            dst[num + (k+16)] = src [i +=dim];
            dst[num + (k+17)] = src [i +=dim];
            dst[num + (k+18)] = src [i +=dim];
            dst[num + (k+19)] = src [i +=dim];
            dst[num + (k+20)] = src [i +=dim];
            dst[num + (k+21)] = src [i +=dim];
            dst[num + (k+22)] = src [i +=dim];
            dst[num + (k+23)] = src [i +=dim];
            dst[num + (k+24)] = src [i +=dim];
            dst[num + (k+25)] = src [i +=dim];
            dst[num + (k+26)] = src [i +=dim];
            dst[num + (k+27)] = src [i +=dim];
            dst[num + (k+28)] = src [i +=dim];
            dst[num + (k+29)] = src [i +=dim];
            dst[num + (k+30)] = src [i +=dim];
            dst[num + (k+31)] = src [i +=dim];
        }
    }
    
    
    /* end of computation for rotate function. any changes you make should be made above this line. */
    /* END OF CHANGES in this function */
    
    /* the remaining lines in this function stop the measurement and set the values before returning. */
    rusage_end_time = getUserTime();
    rdtsc_end_time = rdtsc();
    
    *rusage_time = rusage_end_time - rusage_start_time;
    *rdtsc_time = rdtsc_end_time - rdtsc_start_time;
}
