#include <bits/stdc++.h>
using namespace std;

void DFSVisit(int i, vector<int> &visited, vector<int> &predcessor, vector<int> AdjList[])
{
    cout << i << " ";
    visited[i] = 1;

    for (int j = 0; j < AdjList[i].size(); j++)
    {
        if (visited[i] == 0)
        {
            DFSVisit(j, visited, predcessor, AdjList);
            predcessor[AdjList[i][j]] = i;
        }
    }
}

void DFS(vector<int> AdjList[], int v)
{
    vector<int> visited(v, 0);
    vector<int> predecessor(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            DFSVisit(i, visited, predecessor, AdjList);
        }
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
    }

    cout << "Adjance List:" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    DFS(AdjList, v);
}
