#define pii pair<int, int>
class SegTree {
public:
    SegTree(int _n) {
        n = _n;
        seg.resize(n * 4, 0);
    }
    int query(int x, int y) { return query(x, y, 0, 0, n - 1); }
    void update(int ind, int val) { update(ind, val, 0, 0, n - 1); }

private:
    vector<int> seg;
    int n;

    int query(int x, int y, int i, int l, int r) {
        if (y < l || x > r) {
            return 0;
        }
        if (x <= l && y >= r) {
            return seg[i];
        }

        int mid = (l + r) / 2;
        int left = query(x, y, i * 2 + 1, l, mid);
        int right = query(x, y, i * 2 + 2, mid + 1, r);
        return max(left, right);
    }

    void update(int ind, int val, int i, int l, int r) {
        if (l == r) {
            seg[i] += val;
            return;
        }

        int mid = (l + r) / 2;
        if (ind <= mid) {
            update(ind, val, i * 2 + 1, l, mid);
        } else {
            update(ind, val, i * 2 + 2, mid + 1, r);
        }
        seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<pii> v;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[v[i].second] = i;
        }
        SegTree Tree(n);
        for (int i = 0; i < n; i++) {
            int lb = lower_bound(v.begin(), v.end(), make_pair(nums[i], -1)) - v.begin();
            int val = Tree.query(0, lb - 1) + 1;
            Tree.update(mp[i], val);
        }
        return Tree.query(0, n - 1);
    }
};
