#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b)
{
    return (strcmp(a, b) < 0 ? 1 : 0);
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
    return (strcmp(a, b) < 0 ? 0 : 1);
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int distinct_char_of_a = 0, distinct_char_of_b = 0;
    int a_len = strlen(a), b_len = strlen(b);
    int freq_a[26] = {0};
    int freq_b[26] = {0};
    for (int i = 0; i < a_len; i++)
    {
        freq_a[a[i] - 'a']++;
    }
    for (int i = 0; i < b_len; i++)
    {
        freq_b[b[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq_a[i] != 0)
        {
            distinct_char_of_a++;
        }
        if (freq_b[i] != 0)
        {
            distinct_char_of_b++;
        }
    }

    if (distinct_char_of_a == distinct_char_of_b)
    {
        return lexicographic_sort(a, b);
    }
    else if (distinct_char_of_a < distinct_char_of_b)
    {
        return 1;
    }
    return 0;
}

int sort_by_length(const char *a, const char *b)
{
    int a_len = strlen(a), b_len = strlen(b);
    if (a_len == b_len)
    {
        return lexicographic_sort(a, b);
    }
    else if (a_len < b_len)
    {
        return 1;
    }
    return 0;
}

void swap(char *a, char *b)
{
    char tmp[strlen(a)];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (!((*cmp_func)(arr[j], arr[j + 1])))
            {
                int max_len = strlen(arr[j]) > strlen(arr[j + 1]) ? strlen(arr[j]) : strlen(arr[j + 1]);
                *(arr + j) = realloc(*(arr + j), max_len);
                *(arr + j + 1) = realloc(*(arr + j + 1), max_len);
                arr[j][strlen(arr[j])] = 0;
                arr[j + 1][strlen(arr[j + 1])] = 0;

                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char **arr;
    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
