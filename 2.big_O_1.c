#include<stdio.h>
int main()
{
    int n, i, j, count = 0;

    scanf("%d", &n);

    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
            count += 1;
    }

    printf("n = %d, count = %d", n, count);
    return 0;
}
