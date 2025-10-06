#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                long long s = (long long)nums[i] + nums[l] + nums[r];
                if (s == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    int lv = nums[l], rv = nums[r];
                    while (l < r && nums[l] == lv) ++l;
                    while (l < r && nums[r] == rv) --r;
                } else if (s < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return res;
    }
};
