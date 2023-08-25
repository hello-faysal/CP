#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// Complete the following function.

void calculate_the_maximum(int n, int k)
{
    // Write your code here.
    int s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = i + 1;
    }
    int and_max = 0, or_max = 0, xor_max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = s[i];
            int b = s[j];
            if ((a & b) > and_max && (a & b) < k)
            {
                and_max = (a & b);
            }
            if ((a | b) > or_max && (a | b) < k)
            {
                or_max = (a | b);
            }
            if ((a ^ b) > xor_max && (a ^ b) < k)
            {
                xor_max = (a ^ b);
            }
        }
    }
    printf("%d\n", and_max);
    printf("%d\n", or_max);
    printf("%d\n", xor_max);
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
