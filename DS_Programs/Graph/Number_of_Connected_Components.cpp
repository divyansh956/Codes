#include <bits/stdc++.h>
using namespace std;

void DFSVisit(int i, vector<int> &visited, vector<int> AdjList[], int &cnt)
{
    visited[i] = 1;
    cnt++;

    for (int j = 0; j < AdjList[i].size(); j++)
    {
        if (visited[AdjList[i][j]] == 0)
        {
            DFSVisit(AdjList[i][j], visited, AdjList, cnt);
        }
    }
}

void countComponents(vector<int> AdjList[], int v)
{
    vector<int> visited(v, 0);
    int cnt = 0;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            DFSVisit(i, visited, AdjList, cnt);

            cout << cnt << " ";
            cnt = 0;
        }
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
    }

    countComponents(AdjList, v);
}
