Problem: https://leetcode.com/problems/combination-sum-iii/

/* Koko */

#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
#define PI 3.1415926535897932384626433832795
#define ll long long int
#define ull unsigned long long int
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define all(x) x.begin(), x.end()
#define alln(nums, n) nums, nums + n
#define pb push_back
#define eb emplace_back
#define tsp << " " <<
#define sp " "
#define fi first
#define se second
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define en endl
#define nl cout << en
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loop1(i, s, e) for (ll i = s; i <= e; i++)
#define loop2(i, s, e) for (ll i = s; i < e; i++)
#define rloop(i, n) for (ll i = n - 1; i >= 0; i--)
#define rloop1(i, s, e) for (ll i = s; i >= e; i--)
#define rloop2(i, s, e) for (ll i = s; i > e; i--)

#define vl vector<ll>
#define vi vector<int>
#define umpp unordered_map<ll, ll>
#define mpp map<ll, ll>
#define pii pair<ll, ll>

void print(ll *nums, ll n)
{
    loop(i, n)
    {
        cout << nums[i] << sp;
    }
    cout << en;
}
void printv(vector<ll> &nums)
{
    for (auto x : nums)
    {
        cout << x << sp;
    }
}

class Solution
{
public:
    void findCombination(int k, int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ind == arr.size())
        {
            if (target == 0 && ds.size() == k)
            {
                ans.push_back(ds);
            }
            return;
        }

        if (target < 0)
        {
            return;
        }

        ds.push_back(arr[ind]);
        findCombination(k, ind + 1, target - arr[ind], arr, ans, ds);
        ds.pop_back();

        findCombination(k, ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        findCombination(k, 0, n, candidates, ans, ds);
        return ans;
    }
};
