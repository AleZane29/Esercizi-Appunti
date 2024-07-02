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