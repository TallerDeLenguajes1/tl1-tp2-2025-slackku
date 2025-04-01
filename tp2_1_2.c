#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
    int i;
    double vt[N];
    double *pvt;
    for (i = 0; i < N; i++)
    {
        *vt = 1 + rand() % 100;
        printf("%f", *vt);
        pvt++;
    }
    return 0;
}
