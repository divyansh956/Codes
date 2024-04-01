#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    ll expo(ll a, ll b, ll mod) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }
    ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
    ll mod_add(ll a, ll b, ll m) { return ((((a % m) + (b % m)) % m) + m) % m; }
    ll mod_mul(ll a, ll b, ll m) { return ((((a % m) * (b % m)) % m) + m) % m; }
    ll mod_sub(ll a, ll b, ll m) { return ((((a % m) - (b % m)) % m) + m) % m; }
    ll mod_div(ll a, ll b, ll m) {
        return (mod_mul(a % m, mminvprime(b % m, m), m) + m) % m;
    }
    int strStr(string s, string b) {
        int n = s.length(), m = b.length();
        map<pair<ll, ll>, ll> mp;
        ll p1 = 31, p2 = 29;
        ll hash1 = 0, hash2 = 0, pow1 = 1, pow2 = 1;
        for (int j = 0, i = 0; j < n; j++) {
            if (j - i + 1 <= m) {
                hash1 = mod_add(hash1, mod_mul(pow1, s[j] - 'a' + 1, mod), mod);
                hash2 = mod_add(hash2, mod_mul(pow2, s[j] - 'a' + 1, mod), mod);
                if (j - i + 1 == m) {
                    mp[{hash1, hash2}] = i;
                } else {
                    pow1 = mod_mul(pow1, p1, mod);
                    pow2 = mod_mul(pow2, p2, mod);
                }
            } else {
                hash1 = mod_add(
                    mod_div(mod_sub(hash1, s[i] - 'a' + 1, mod), p1, mod),
                    mod_mul(pow1, s[j] - 'a' + 1, mod), mod);
                hash2 = mod_add(
                    mod_div(mod_sub(hash2, s[i] - 'a' + 1, mod), p2, mod),
                    mod_mul(pow2, s[j] - 'a' + 1, mod), mod);
                i++;
                if (mp.find({hash1, hash2}) == mp.end()) {
                    mp[{hash1, hash2}] = i;
                }
            }
        }
        hash1 = 0, hash2 = 0, pow1 = 1, pow2 = 1;
        for (int j = 0; j < m; j++) {
            hash1 = mod_add(hash1, mod_mul(pow1, b[j] - 'a' + 1, mod), mod);
            hash2 = mod_add(hash2, mod_mul(pow2, b[j] - 'a' + 1, mod), mod);
            pow1 = mod_mul(pow1, p1, mod);
            pow2 = mod_mul(pow2, p2, mod);
        }
        return (mp.find({hash1, hash2}) == mp.end() ? -1 : mp[{hash1, hash2}]);
    }
};

#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> stringIndices(vector<string>& words, vector<string>& queries) {
        ll p1 = 31, p2 = 29;
        vector<int> ans;
        ll ind = 0, mn = -1, len = 1e7;
        map<pair<ll, ll>, pair<ll, ll>> mp;
        for (auto s : words) {
            ll m = s.length(), hash1 = 0, hash2 = 0, pow1 = 1, pow2 = 1;
            if (len > m) {
                len = m;
                mn = ind;
            }
            for (ll j = m - 1; j >= 0; j--) {
                hash1 += (pow1 * (s[j] - 'a' + 1)) % mod;
                hash2 += (pow2 * (s[j] - 'a' + 1)) % mod;
                pow1 = (pow1 * p1) % mod;
                pow2 = (pow2 * p2) % mod;

                if (mp.find({hash1, hash2}) == mp.end()) {
                    mp[{hash1, hash2}] = {m, ind};
                } else {
                    auto [sz, index] = mp[{hash1, hash2}];
                    if (sz > m) {
                        sz = m;
                        index = ind;
                    }
                    mp[{hash1, hash2}] = {sz, index};
                }
            }
            ind++;
        }

        for (auto s : queries) {
            ll m = s.length(), hash1 = 0, hash2 = 0, pow1 = 1, pow2 = 1, res = mn;
            for (ll j = m - 1; j >= 0; j--) {
                hash1 += (pow1 * (s[j] - 'a' + 1)) % mod;
                hash2 += (pow2 * (s[j] - 'a' + 1)) % mod;
                pow1 = (pow1 * p1) % mod;
                pow2 = (pow2 * p2) % mod;
                if (mp.find({hash1, hash2}) != mp.end()) {
                    auto [sz, index] = mp[{hash1, hash2}];
                    res = index;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
