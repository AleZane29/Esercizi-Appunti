#include <stdio.h>
// PRE:
// POST:
void swap_eq(int *a, int dim, int i, int j, int n)
{
    if (n == 0)
    {
        return;
    }
    int tmp = a[i + n - 1];
    a[i + n - 1] = a[j + n - 1];
    a[j + n - 1] = tmp;
    swap_eq(a, dim, i, j, n - 1);
}

// PRE:
// POST:
void swap(int *a, int dim, int m, int n, int p)
{
    if (n - m == p - n)
    {
        swap_eq(a, dim, m, n, n - m);
        return;
    }
    else if (n - m < p - n)
    {
        swap_eq(a, dim, m, n, n - m);
        swap(a, dim, n, n + n - m, p);
    }
    else if (n - m > p - n)
    {
        swap_eq(a, dim, m, n, p - n);
        swap(a, dim, m + p - n, n, p);
    }
}

int main(void)
{
    int dim;
    int m;
    int n;
    int p;

    scanf("%d", &dim);
    int arr[dim];
    for (int i = 0; i < dim; i++)
    {
        scanf("%d", arr + i);
    }

    void print_array(int *a, int d)
    {
        for (int i = 0; i < d; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &p);

    swap(arr, dim, m, n, p);
    print_array(arr, dim);
}
