#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "How many Vertices are There: ";
    int v;
    cin >> v;

    cout << "How many Edges are There: ";
    int e;
    cin >> e;

    vector<int> AdjList[v];
    vector<vector<int>> AdjMat(v, vector<int>(v, 0));
    vector<vector<int>> IncMat(v, vector<int>(e, 0));

    for (int i = 1; i <= e; i++)
    {
        cout << "Enter the End Points of Edge " << i << ": ";
        int a, b;
        cin >> a >> b;

        AdjMat[a][b] = 1;
        AdjMat[b][a] = 1;

        IncMat[a][i - 1] = 1;
        IncMat[b][i - 1] = 1;

        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
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

    cout << "Adjance Matrix:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Incidence Matrix:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cout << IncMat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Degree:" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << ": " << AdjList[i].size();
        cout << endl;
    }
    cout << endl;
}
