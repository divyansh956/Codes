#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> AdjList[], int v)
{
    vector<int> visited(v, 0);

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < AdjList[x].size(); i++)
        {
            if (visited[AdjList[x][i]] == 0)
            {
                q.push(AdjList[x][i]);
                visited[AdjList[x][i]] = 1;
            }
        }

        cout << x << " ";
    }
}

int main()
{
    int v;
    cin >> v;

    int e;
    cin >> e;

    vector<int> AdjList[v];

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;

        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }

    BFS(AdjList, v);
}
