#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long closestDiff = LLONG_MAX;
        int closestSum = 0;

        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            int l = i + 1, r = (int)nums.size() - 1;
            while (l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];
                long long diff = llabs(sum - target);

                if (diff < closestDiff) {
                    closestDiff = diff;
                    closestSum = (int)sum;
                }
                if (sum == target) return target;
                if (sum < target) ++l; else --r;
            }
        }
        return closestSum;
    }
};
