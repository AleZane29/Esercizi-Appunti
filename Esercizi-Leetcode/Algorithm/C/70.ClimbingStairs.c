// Restituisce il numero di possibilità di salire una scala di n gradini, potendo fare passi da 1 o 2 gradini (Fibonacci)
int climbStairs(int n)
{
    int res = 1;
    int pre = 1;
    for (int i = 0; i < n - 1; i++)
    {
        res += pre;
        pre = res - pre;
    }
    return res;
}