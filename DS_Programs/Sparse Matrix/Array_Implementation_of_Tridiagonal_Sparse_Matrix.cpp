#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int sz = 0;
	vector<vector<int>> S(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> S[i][j];
			if (S[i][j] != 0)
			{
				sz++;
			}
		}
	}

	vector<int> ans(sz);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (S[i][j] != 0)
			{
				int temp = ((i + 1) * 2) + j - 1;
				ans[temp - 1] = S[i][j];
			}
		}
	}

	for (int i = 0; i < sz; i++)
	{
		cout << ans[i] << " ";
	}
}
