#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> AdjList[], int v)
{
    vector<int> visited(v, 0);
    vector<int> distance(v, 0);
    vector<int> predecessor(v, -1);

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    cout << "BFS: ";
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
                predecessor[AdjList[x][i]] = x;
                distance[AdjList[x][i]] = distance[x] + 1;
            }
        }

        cout << x << " ";
    }
    cout << endl;

    cout << "Distance: ";
    for (auto x : distance)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Precedessor: ";
    for (auto x : predecessor)
    {
        cout << x << " ";
    }
    cout << endl;
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
