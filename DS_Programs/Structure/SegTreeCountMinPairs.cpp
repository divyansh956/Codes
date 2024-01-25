#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct item
{
	ll m, c;
};

class SegTree
{
public:
	SegTree(vector<ll> v, ll _n)
	{
		n = _n;
		seg.resize(n * 4);
		build(0, 0, n - 1, v);
	}

	item query(ll x, ll y)
	{
		return query(x, y, 0, 0, n - 1);
	}

	void update(ll ind, ll val)
	{
		update(ind, val, 0, 0, n - 1);
	}

private:
	vector<item> seg;
	ll n;

	item single(ll val)
	{
		return {val, 1ll};
	}

	item merge(item a, item b)
	{
		if (a.m < b.m) return a;
		if (a.m > b.m) return b;
		else return {a.m, a.c + b.c};
	}

	void build(ll i, ll l, ll r, const vector<ll> &v)
	{
		if (l == r)
		{
			seg[i] = single(v[l]);
			return;
		}

		ll mid = (l + r) / 2;
		build(i * 2 + 1, l, mid, v);
		build(i * 2 + 2, mid + 1, r, v);
		seg[i] = merge(seg[i * 2 + 1] , seg[i * 2 + 2]);
	}

	item query(ll x, ll y, ll i, ll l, ll r)
	{
		if (y < l || x > r) return single(1e10);
		if (x <= l && y >= r) return seg[i];

		ll mid = (l + r) / 2;
		item left = query(x, y, i * 2 + 1, l, mid);
		item right = query(x, y, i * 2 + 2, mid + 1, r);
		return merge(left , right);
	}

	void update(ll ind, ll val, ll i, ll l, ll r)
	{
		if (l == r)
		{
			seg[i] = single(val);
			return;
		}

		ll mid = (l + r) / 2;
		if (ind <= mid)	update(ind, val, i * 2 + 1, l, mid);
		else update(ind, val, i * 2 + 2, mid + 1, r);
		seg[i] = merge(seg[i * 2 + 1] , seg[i * 2 + 2]);
	}
};

void sol()
{
	ll n, q;
	cin >> n >> q;

	vector<ll> v(n);
	for (auto &x : v) cin >> x;
	SegTree Tree(v, n);

	while (q--)
	{
		ll type;
		cin >> type;

		if (type == 1)
		{
			ll i, k;
			cin >> i >> k;

			Tree.update(i, k);
			v[i] = k;
		}
		else
		{
			ll l, r;
			cin >> l >> r;

			item p = Tree.query(l, r - 1);
			cout << p.m << " " << p.c << endl;
		}
	}
}

int32_t main()
{
  ll tc = 1;
	// cin >> tc;
	while (tc--)
	{
		sol();
	}
}
