#include <bits/stdc++.h>
using namespace std;

void DFSVisit(int i, vector<int> &visited, vector<int> AdjList[], stack<int> &s)
{
    visited[i] = 1;

    for (int j = 0; j < AdjList[i].size(); j++)
    {
        if (visited[AdjList[i][j]] == 0)
        {
            DFSVisit(AdjList[i][j], visited, AdjList, s);
        }
    }
    s.push(i);
}

void TopologicalSort(vector<int> AdjList[], int v)
{
    vector<int> visited(v, 0);
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            DFSVisit(i, visited, AdjList, s);
        }
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
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

    TopologicalSort(AdjList, v);
}
