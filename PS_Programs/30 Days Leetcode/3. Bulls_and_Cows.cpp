Problem: https://leetcode.com/problems/bulls-and-cows/

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
    string getHint(string secret, string guess)
    {
        umpp mp1;
        umpp mp2;

        ll n = secret.length();
        ll cnt1 = 0, cnt2 = 0;

        loop(i, n)
        {
            if (secret[i] == guess[i])
            {
                cnt1++;
            }
            else
            {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }

        for (auto x : mp1)
        {
            if (mp2.find(x.fi) != mp2.end())
            {
                cnt2 += min(mp2[x.fi], mp1[x.fi]);
            }
        }

        return to_string(cnt1) + "A" + to_string(cnt2) + "B";
    }
};
