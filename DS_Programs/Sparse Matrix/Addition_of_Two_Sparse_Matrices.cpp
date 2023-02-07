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

sparse *makeLinkedList(vector<vector<int>> &S)
{
	int n = S.size();
	sparse *head = NULL;
	sparse *p = head;

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
	return head;
}

sparse *addSparseMatrix(sparse *head1, sparse *head2)
{
	sparse *head3 = NULL;
	sparse *p = head3;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->row == head2->row)
		{
			if (head1->coloumn == head2->coloumn)
			{
				int sum = head1->data + head2->data;
				auto newx = new sparse(head1->row, head2->coloumn, sum);

				if (head3 == NULL)
				{
					head3 = newx;
					p = head3;
				}
				else
				{
					p->next = newx;
					p = p->next;
				}
				head1 = head1->next;
				head2 = head2->next;
			}
			else if (head1->coloumn < head2->coloumn)
			{
				auto newx = head1;

				if (head3 == NULL)
				{
					head3 = newx;
					p = head3;
				}
				else
				{
					p->next = newx;
					p = p->next;
				}
				head1 = head1->next;
			}
			else
			{
				auto newx = head2;

				if (head3 == NULL)
				{
					head3 = newx;
					p = head3;
				}
				else
				{
					p->next = newx;
					p = p->next;
				}
				head2 = head2->next;
			}
		}
		else if (head1->row < head2->row)
		{
			auto newx = head1;

			if (head3 == NULL)
			{
				head3 = newx;
				p = head3;
			}
			else
			{
				p->next = newx;
				p = p->next;
			}
			head1 = head1->next;
		}
		else
		{
			auto newx = head2;

			if (head3 == NULL)
			{
				head3 = newx;
				p = head3;
			}
			else
			{
				p->next = newx;
				p = p->next;
			}
			head2 = head2->next;
		}
	}

	while (head1 != NULL)
	{
		auto newx = head1;

		if (head3 == NULL)
		{
			head3 = newx;
			p = head3;
		}
		else
		{
			p->next = newx;
			p = p->next;
		}
		head1 = head1->next;
	}

	while (head2 != NULL)
	{
		auto newx = head1;

		if (head3 == NULL)
		{
			head3 = newx;
			p = head3;
		}
		else
		{
			p->next = newx;
			p = p->next;
		}
		head2 = head2->next;
	}

	return head3;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> S1(n, vector<int>(n, 0));
	vector<vector<int>> S2(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> S1[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> S2[i][j];
		}
	}

	sparse *head1 = makeLinkedList(S1);
	sparse *head2 = makeLinkedList(S2);

	sparse *head3 = addSparseMatrix(head1, head2);

	sparse *p = head3;
	cout << "R C Val" << endl;

	while (p != NULL)
	{
		cout << p->row << " " << p->coloumn << " " << p->data;
		p = p->next;
		cout << endl;
	}
}
