#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 7
int main()
{
    int i, j;
    int mt[N][M];
    int *p_mt;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *p_mt = 1 + rand() % 100;
            printf("%d ", *p_mt);
            p_mt++;
        }
        printf("\n");
    }
}
