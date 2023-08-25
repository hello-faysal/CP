#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

double calc_area(triangle *tr, int i)
{
    double p = ((tr[i]).a + tr[i].b + tr[i].c) / 2.0;
    double s = sqrt((p * (p - (tr[i].a)) * (p - (tr[i].b)) * (p - (tr[i].c))));
    return s;
}

void swap(triangle *a, triangle *b)
{
    triangle tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_by_area(triangle *tr, int n)
{
    /**
     * Sort an array a of the length n
     */
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i; j < n; j++)
        {
            if ((double)calc_area(tr, j) < (double)calc_area(tr, min_index))
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(&tr[i], &tr[min_index]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}