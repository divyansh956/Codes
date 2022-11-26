int divisor(int n)
{
    string ss = to_string(n);
    int ans = 0;
    int mx = -1;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;

        if (n % i == 0)
        {
            string temp = to_string(i);
            for (int j = 0; j < temp.length(); j++)
            {
                sum += (temp[j] - '0');
            }
        }
        if (sum > mx)
        {
            mx = sum;
            ans = i;
        }
    }
    return ans;
}
