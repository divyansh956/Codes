#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> APSPfloydWarshell(vector<vector<int>> &W, int v)
{
	vector<vector<int>> D(v + 1, vector<int>(v + 1, 0));

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (W[i][j] == 0)
			{
				if (i != j)
				{
					D[i][j] = INT_MAX / 2;
				}
			}
			else
			{
				D[i][j] = W[i][j];
			}
		}
	}

	for (int k = 1; k <= v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	return D;
}

int main()
{
	int v;
	cin >> v;

	int e;
	cin >> e;

	vector<vector<int>> W(v + 1, vector<int>(v + 1, 0));

	for (int i = 1; i <= e; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		W[a][b] = w;
	}

	vector<vector<int>> tc = APSPfloydWarshell(W, v);
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			cout << tc[i][j] << " ";
		}
		cout << endl;
	}
}
