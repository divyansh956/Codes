/* KoKo */

#include <bits/stdc++.h>
using namespace std;

#define mod1 1000000007
#define mod2 998244353
#define PI 3.1415926535897932384626433832795
#define ll long long int
#define ull unsigned long long int
#define lld long double
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define mkp make_pair
#define en endl
#define nl cout << en
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define rloop(i, a, b) for (ll i = a; i >= b; i--)

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif

const ll INF = 1e18;
const ll N = 1e5 + 7;
ll dx[] = { -1, 0, +1, 0};
ll dy[] = {0, +1, 0, -1};
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
ll max(ll a, ll b) { return (a > b) ? a : b; }
ll min(ll a, ll b) { return (a < b) ? a : b; }
ll ceil(ll a, ll b) { return (a + b - 1) / b; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;   } return res;}
ll pow(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a); b = b >> 1;   } return res;}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll getBit(ll n, ll ind) { return ((n & (1 << ind)) != 0); }
ll mod_add(ll a, ll b, ll m) { return ((((a % m) + (b % m)) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((((a % m) * (b % m)) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((((a % m) - (b % m)) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m) { return (mod_mul(a % m, mminvprime(b % m, m), m) + m) % m; }
ll fact(ll n) {ll res = 1; loop(i, 1, n + 1) {res = (res * 1ll * i) % mod1;} return res;}
ll ncr(ll n, ll r) {ll cnt1 = 1; loop(i, 0, r) {cnt1 *= (n - i); cnt1 /= (i + 1);} return cnt1;}
ll nCr(ll n, ll k) {return (mod_mul(fact(n), expo(fact(k), mod1 - 2, mod1), mod1) * expo(fact(n - k), mod1 - 2, mod1)) % mod1;}
vector<ll> sieve(ll n) {vector<ll> nums(n + 1); vector<ll> vect; loop(i, 2, n + 1) {if (nums[i] == 0) {vect.pb(i); for (ll j = 2 * i; j <= n; j += i) {nums[j] = 1;}}} return vect;}
bool isPrime(ll n) {if (n == 1) { return false;} loop(i, 2, sqrt(n) + 1) {if (n % i == 0) {return false;}} return true;}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
void precision(int a) { cout << setprecision(a) << fixed; }
void input(vector<ll> &nums) { for (auto &x : nums) cin >> x; }
void printv(vector<ll> &nums) { for (auto x : nums) cout << x << " "; nl;}
bool cmp(vector<ll> &a, vector<ll> &b) { return a < b; }

unordered_map<ll, ll>mp;
class SegTree
{
public:
	SegTree(ll _n)
	{
		n = _n;
		seg.resize(n * 4, 0);
	}

	ll query(ll x, ll y)
	{
		return query(x, y, 0, 0, n - 1);
	}

	void update(ll ind, ll val)
	{
		update(ind, val, 0, 0, n - 1);
	}

private:
	vector<ll> seg;
	ll n;

	ll query(ll x, ll y, ll i, ll l, ll r)
	{
		if (y < l || x > r) return 0;
		if (x <= l && y >= r) return seg[i];

		ll mid = (l + r) / 2;
		ll left = query(x, y, i * 2 + 1, l, mid);
		ll right = query(x, y, i * 2 + 2, mid + 1, r);
		return left + right;
	}

	void update(ll ind, ll val, ll i, ll l, ll r)
	{
		if (l == r)
		{
			seg[i] += val;
			return;
		}

		ll mid = (l + r) / 2;
		if (ind <= mid)	update(ind, val, i * 2 + 1, l, mid);
		else update(ind, val, i * 2 + 2, mid + 1, r);
		seg[i] = seg[i * 2 + 1] + seg[i * 2 + 2];
	}
};

void sol()
{
	ll n;
	cin >> n;

	vector<ll> a(n), v;
	input(a);
	v = a;
	sort(all(v));
	loop(i, 0, n)
	{
		mp[v[i]] = i;
	}
	SegTree Tree(n);

	ll ans = 0;
	loop(i, 0, n)
	{
		ll pos = mp[a[i]];
		ll greater_in_left = Tree.query(pos + 1, n - 1);

		ans += greater_in_left * (pos - i + greater_in_left);
		Tree.update(mp[a[i]], 1);
	}
	cout << ans;
	nl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif

	ll tc = 1;
	cin >> tc;
	precision(0);

	loop(i, 0, tc)
	{
		sol();
	}
}
