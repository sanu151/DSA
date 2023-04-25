#include<stdio.h>
int main()
{
    int n, i, j, count = 0;

    printf("Enter n : ");
    scanf("%d", &n);

    for(i = 0; i<n; i++) // first loop gives time complexity O(n)
    {
        for(j = 0; j<n; j++) // Second loop may gives time complexity O(n)^2
            count += 1;
    }

    printf("n = %d, count = %d", n, count); // Count is square of n
    return 0;
}
