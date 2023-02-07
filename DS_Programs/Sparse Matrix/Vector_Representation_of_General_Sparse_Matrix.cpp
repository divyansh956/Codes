#include <bits/stdc++.h>
using namespace std;

class sparse
{
public:
	int row;
	int coloumn;
	int data;

	sparse(int i, int j, int val)
	{
		row = i;
		coloumn = j;
		data = val;
	}
};

int main()
{
	int n;
	cin >> n;

	int sz = 0;
	vector<vector<int>> S(n, vector<int>(n, 0));
	vector<sparse *> ans;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> S[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (S[i][j] != 0)
			{
				auto newx = new sparse(i, j, S[i][j]);
				ans.push_back(newx);
			}
		}
	}

	cout << "R C Val" << endl;
	for (auto x : ans)
	{
		cout << x->row << " " << x->coloumn << " " << x->data;
		cout << endl;
	}
}
