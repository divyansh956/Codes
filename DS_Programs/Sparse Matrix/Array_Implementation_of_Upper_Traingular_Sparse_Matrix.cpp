#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> S(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> S[i][j];
		}
	}

	int sz = ((n) * (n + 1)) / 2;
	vector<int> ans(sz);

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int temp = ((n) * (n + 1)) / 2 - ((n - i) * (n - i + 1)) / 2 + j - i + 1;
			ans[temp - 1] = S[i][j];
		}
	}

	for (int i = 0; i < sz; i++)
	{
		cout << ans[i] << " ";
	}
}
