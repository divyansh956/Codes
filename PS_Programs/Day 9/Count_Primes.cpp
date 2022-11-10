class Solution
{
public:
    int countPrimes(int n)
    {
        int idx[5000001] = {0};

        for (int i = 2; i < n; i++)
        {
            if (idx[i] == 0)
            {
                for (int j = i * 2; j < n; j += i)
                {
                    idx[j] = 1;
                }
            }
        }

        int cnt = 0;

        for (int i = 2; i < n; i++)
        {
            if (idx[i] == 0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
