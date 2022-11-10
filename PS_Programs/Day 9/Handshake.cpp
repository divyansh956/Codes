int handshake(int n)
{
    int r = 2;

    if (n == 1)
    {
        return 0;
    }
    
    if (r > n - r)
    {
        r = n - r;
    }

    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
