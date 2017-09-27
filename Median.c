#include <stdlib.h>
#include <string.h>
#define N 101
/*
 * XOR Shift rng
 * get    : min max and seed*
 * return : random number
 * modify : seed
 */
int f(int m, int M, unsigned int* s)
{
    *s ^= (unsigned int)(*s << 13);
    *s ^= (unsigned int)(*s >> 17);
    *s ^= (unsigned int)(*s << 5);
    return m + (*s%(M-m));
}

void f2(int* a,int* b, int c)
{
        if(c==0) return;
        int t = *b;
        *b = *a;
        *a = t;
}

void f1(int* a)
{
    int t, i, j;
    for(i = 0; i<N; i++)
        for(j=N-1; j>i; --j)
            f2(&a[j], &a[j-1], a[j] < a[j-1]);
}

int median()
{
    unsigned int seed = 42;
    int b=0, i;
    int* a = (int*) malloc(4 * N);
    for(i=0;i<N;i++)
       a[i] = f(-10, 11, &seed);
    f1(a);
    b = a[N/2];
    free(a);
    return b;
}

