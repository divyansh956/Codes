#include <bits/stdc++.h>
using namespace std;

void countDegree(vector<int> AdjList[], int v)
{
    vector<int> Outdegree;
    vector<int> Indegree(v);

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            Indegree[AdjList[i][j]]++;
        }
        Outdegree.push_back(AdjList[i].size());
    }

    cout << "Indegree: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << ": " << Indegree[i];
        cout << endl;
    }
    cout << endl;

    cout << "Outdegree: " << endl;
    for (int i = 0; i < Outdegree.size(); i++)
    {
        cout << i << ": " << Outdegree[i];
        cout << endl;
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

    countDegree(AdjList, v);
}
