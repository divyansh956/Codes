//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int multiply(int arr[], int n);

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum1 = 0, sum2 = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << multiply(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// User function Template for C++

int multiply(int arr[], int n)
{
    int left = 0, right = 0;
    for (int i = 0; i < n / 2; i++)
    {
        left += arr[i];
    }
    for (int i = n - 1; i >= n / 2; i--)
    {
        right += arr[i];
    }
    return left * right;
}
