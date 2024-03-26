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
void sol() {
    string s, b;
    cin >> s >> b;
    ll n = s.length(), m = b.length();
    map<pair<ll, ll>, vector<ll>> mp;
    ll p1 = 31, p2 = 29;
    ll hash1 = 0, hash2 = 0, pow1 = 1, pow2 = 1;
    for (int j = 0, i = 0; j < n; j++) {
        if (j - i + 1 <= m) {
            hash1 = mod_add(hash1, mod_mul(pow1, s[j] - 'a' + 1, mod), mod);
            hash2 = mod_add(hash2, mod_mul(pow2, s[j] - 'a' + 1, mod), mod);
            if (j - i + 1 == m) {
                mp[{hash1, hash2}].push_back(i);
            } else {
                pow1 = mod_mul(pow1, p1, mod);
                pow2 = mod_mul(pow2, p2, mod);
            }
        } else {
            hash1 =
                mod_add(mod_div(mod_sub(hash1, s[i] - 'a' + 1, mod), p1, mod),
                        mod_mul(pow1, s[j] - 'a' + 1, mod), mod);
            hash2 =
                mod_add(mod_div(mod_sub(hash2, s[i] - 'a' + 1, mod), p2, mod),
                        mod_mul(pow2, s[j] - 'a' + 1, mod), mod);
            mp[{hash1, hash2}].push_back(++i);
        }
    }
    hash1 = 0, hash2 = 0, pow1 = 1, pow2 = 1;
    for (int j = 0; j < m; j++) {
        hash1 = mod_add(hash1, mod_mul(pow1, b[j] - 'a' + 1, mod), mod);
        hash2 = mod_add(hash2, mod_mul(pow2, b[j] - 'a' + 1, mod), mod);
        pow1 = mod_mul(pow1, p1, mod);
        pow2 = mod_mul(pow2, p2, mod);
    }
}
