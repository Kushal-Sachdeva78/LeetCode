#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), l = 0, r = n - 1, lm = 0, rm = 0, ans = 0;
        while (l < r) {
            if (h[l] < h[r]) {
                lm = max(lm, h[l]);
                ans += lm - h[l];
                ++l;
            } else {
                rm = max(rm, h[r]);
                ans += rm - h[r];
                --r;
            }
        }
        return ans;
    }
};
