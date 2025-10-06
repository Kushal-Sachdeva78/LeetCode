#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int lv = nums[l], rv = nums[r];
                        while (l < r && nums[l] == lv) ++l;
                        while (l < r && nums[r] == rv) --r;
                    } else if (sum < target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }
        return res;
    }
};
