#include <stdio.h>

// Dato un array restituisce 1 se esiste una combinazione di suoi elementi che sommati danno target, altrimenti 0
int search_sum(int *a, int dim, int target)
{
    for (int n = 0; n < dim; n++)
    {
        if (target == a[n])
        {
            return 1;
        }
    }
    for (int n = 0; n < dim; n++)
    {
        if (a[n] < target)
        {
            if (search_sum(a, dim, target - a[n]) == 1)
            {
                return 1;
            };
        }
    }
    return 0;
}

int main()
{
    int a[] = {5, 2, 4, 8};
    printf("Exist? %d", search_sum(a, 4, 18));
    return 0;
}