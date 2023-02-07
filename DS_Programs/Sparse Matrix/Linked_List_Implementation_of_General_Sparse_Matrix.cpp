#include <bits/stdc++.h>
using namespace std;

class sparse
{
public:
	int row;
	int coloumn;
	int data;
	sparse *next;

	sparse(int i, int j, int val)
	{
		row = i;
		coloumn = j;
		data = val;
		next = NULL;
	}
};

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> S(n, vector<int>(n, 0));
	sparse *head = NULL;
	sparse *p = head;

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
				if (head == NULL)
				{
					head = newx;
					p = head;
				}
				else
				{
					p->next = newx;
					p = p->next;
				}
			}
		}
	}

	p = head;
	cout << "R C Val" << endl;

	while (p != NULL)
	{
		cout << p->row << " " << p->coloumn << " " << p->data;
		p = p->next;
		cout << endl;
	}
}
