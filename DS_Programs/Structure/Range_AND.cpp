/*
TLE WHY?

#define ll long long int
class Solution {
public:
    vector<vector<ll>> res;
    int minimumDifference(vector<int>& nums, int val) {
        int n = nums.size();
        res.clear();
        for (ll i = 0; i < n; i++) {
            bitset<30> b(nums[i]);
            vector<ll> temp;
            for (ll j = 29; j >= 0; j--) {
                temp.push_back(b[j]);
            }
            res.push_back(temp);
        }

        for (ll i = 1; i < n; i++) {
            for (ll j = 0; j < 30; j++) {
                res[i][j] += res[i - 1][j];
            }
        }

        ll mn = 1e15;
        for (int ind = 0; ind < n; ind++) {
            ll low = ind, high = n - 1;
            while (low <= high) {
                ll mid = (low + high) / 2;
                vector<ll> curr = res[mid];
                ll curVal = 0;
                for (ll j = 0; j < 30; j++) {
                    if (ind > 0) {
                        curr[j] -= res[ind - 1][j];
                    }
                    if (curr[j] == mid - ind + 1) {
                        curVal += 1ll << (30 - j - 1);
                    }
                }

                if (curVal <= val) {
                    mn = min(mn, abs(curVal - val));
                    high = mid - 1;
                } else {
                    mn = min(mn, abs(curVal - val));
                    low = mid + 1;
                }
            }
        }

        return mn;
    }
};
*/

class Solution {
    class SegmentTree {
    public:
        SegmentTree(const vector<int>& nums) {
            n = nums.size();
            tree.resize(2 * n);
            build(nums);
        }

        int rangeAND(int left, int right) {
            left += n;
            right += n + 1;
            int result = INT_MAX;
            while (left < right) {
                if (left % 2 == 1) {
                    result &= tree[left];
                    left++;
                }
                if (right % 2 == 1) {
                    right--;
                    result &= tree[right];
                }
                left /= 2;
                right /= 2;
            }
            return result;
        }

    private:
        vector<int> tree;
        int n;

        void build(const vector<int>& nums) {
            for (int i = 0; i < n; i++) {
                tree[i + n] = nums[i];
            }
            for (int i = n - 1; i > 0; --i) {
                tree[i] = tree[2 * i] & tree[2 * i + 1];
            }
        }
    };

    int minAbsDifference(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree segTree(nums);
        int minDiff = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int left = i, right = n - 1, bestDiff = INT_MAX;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int currentAND = segTree.rangeAND(i, mid);
                int diff = abs(currentAND - k);
                bestDiff = min(bestDiff, diff);
                if (diff == 0) {
                    return 0;
                }
                if (currentAND >= k) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            minDiff = min(minDiff, bestDiff);
        }

        return minDiff;
    }

public:
    int minimumDifference(vector<int>& nums, int k) {
        return minAbsDifference(nums, k);
    }
};
