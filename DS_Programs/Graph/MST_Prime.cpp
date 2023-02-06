#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

int main()
{
	int N, E, i, a, b, cost;
	cin >> N;

	vector<pair<int, int>> adj[N];
	cin >> E;

	for (i = 1; i <= E; i++)
	{
		cin >> a >> b >> cost;
		adj[a].push_back({b, cost});
		adj[b].push_back({a, cost});
	}

	for (i = 0; i < N; i++)
	{
		int j = 0;
		cout << i << ": ";

		for (int j = 0; j < adj[i].size(); j++)
		{
			cout << "(" << adj[i][j].first << ",";
			cout << adj[i][j].second << "), ";
		}

		cout << endl;
	}

	vector<int> InPQ(N, 0);
	vector<int> key(N, INT_MAX);
	vector<int> predecessor(N, -1);

	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
	int source;

	cout << endl;
	cin >> source;

	pq.push({0, source});
	key[source] = 0;

	for (i = 0; i < N && i != source; i++)
	{
		pq.push({INT_MAX, i});
	}

	for (i = 1; i <= N - 1; i++)
	{
		pair<int, int> x = pq.top();
		pq.pop();

		int v = x.second;
		InPQ[v] = 1;

		for (int j = 0; j < adj[v].size(); j++)
		{
			int vertex = adj[v][j].first;
			int weight = adj[v][j].second;

			if (InPQ[vertex] == 0 && key[vertex] > weight)
			{
				key[vertex] = weight;
				predecessor[vertex] = v;
				pq.push({key[vertex], vertex});
			}
		}
	}

	cout << "vertex    key"
		 << "  Predecessor" << endl;

	for (i = 0; i < N; i++)
	{
		cout << i << "\t";
		cout << key[i] << "\t";
		cout << predecessor[i];
		cout << endl;
	}
}
