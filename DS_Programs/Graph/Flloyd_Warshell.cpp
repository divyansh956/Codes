#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> TCflloydWarshell(vector<vector<int>> AdjMat, int v)
{
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                AdjMat[i][j] = AdjMat[i][j] | (AdjMat[i][k] & AdjMat[k][j]);
            }
        }
    }

    return AdjMat;
}

int main()
{
    int v;
    cin >> v;

    int e;
    cin >> e;

    vector<vector<int>> AdjMat(v, vector<int>(v, 0));

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;

        AdjMat[a][b] = 1;
        AdjMat[b][a] = 1;
    }

    vector<vector<int>> tc = TCflloydWarshell(AdjMat, v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << tc[i][i] << " ";
        }
        cout << endl;
    }
}
