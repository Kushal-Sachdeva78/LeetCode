class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                ans = m;
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                ans = m;
                l = m + 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};
