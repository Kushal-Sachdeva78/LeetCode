#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = (int)height.size() - 1;
        long long best = 0;
        while (i < j) {
            long long h = min(height[i], height[j]);
            best = max(best, h * (j - i));
            if (height[i] < height[j]) ++i;
            else --j;
        }
        return (int)best;
    }
};
