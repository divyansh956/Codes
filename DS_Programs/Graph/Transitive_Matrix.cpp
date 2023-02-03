#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixAdd(vector<vector<int>> &m1, vector<vector<int>> &m2)
{
    int n = m1.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return ans;
}

vector<vector<int>> matrixMultiply(vector<vector<int>> &m1, vector<vector<int>> &m2)
{
    int n = m1.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += (m1[i][k] * m2[k][j]);
            }
        }
    }
    return ans;
}

vector<vector<int>> TransitiveMatrix(vector<vector<int>> &AdjMat, int v)
{
    vector<vector<int>> tc = AdjMat;
    vector<vector<int>> t = AdjMat;

    for (int k = 1; k < v; k++)
    {
        t = matrixMultiply(t, AdjMat);
        tc = matrixAdd(tc, t);
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (tc[i][j] != 0)
            {
                tc[i][j] = 1;
            }
        }
    }

    return tc;
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
    }

    vector<vector<int>> tc = TransitiveMatrix(AdjMat, v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << tc[i][j] << " ";
        }
        cout << endl;
    }
}
