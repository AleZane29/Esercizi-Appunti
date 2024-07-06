#include <stdio.h>

void elimina_pal(char *s)
{
    int dim = 0;
    while (s[dim] != '\0')
    {
        dim++;
    }
    for (int i = 0; i <= (dim + 1) / 2; i++)
    {
        if (s[i] == s[dim - i - 1])
        {

            for (int n = i; n <= dim - 2; n++)
            {

                if (n >= dim - i - 2 && i != dim - i - 1)
                {
                    s[n] = s[n + 1 + 1];
                }
                else
                {
                    s[n] = s[n + 1];
                }
            }
            if (i == dim - i - 1)
            {
                dim--;
            }
            else
            {

                dim = dim - 2;
            }
            s[dim] = '\0';
        }
    }
}

int main()
{
    char s[50];
    scanf("%s", s);

    elimina_pal(s);

    printf("%s", s);

    return 0;
}
