#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class SegTree
{
public:
	SegTree(vector<ll> v, ll _n)
	{
		n = _n;
		seg.resize(n * 4, 0);
		build(0, 0, n - 1, v);
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

	void build(ll i, ll l, ll r, const vector<ll> &v)
	{
		if (l == r)
		{
			seg[i] = v[l];
			return;
		}

		ll mid = (l + r) / 2;
		build(i * 2 + 1, l, mid, v);
		build(i * 2 + 2, mid + 1, r, v);
		seg[i] = seg[i * 2 + 1] + seg[i * 2 + 2];
	}

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
			seg[i] = val;
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

			cout << Tree.query(l, r - 1) << endl;
		}
	}
}

int main()
{
	ll tc = 1;
	// cin >> tc;
	while (tc--)
	{
		sol();
	}
}
