#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int r = matrix.size(), c = matrix[0].size();
        vector<int> h(c, 0);
        int ans = 0;

        auto max_histogram = [&](vector<int>& a) {
            vector<int> st;
            int best = 0;
            for (int i = 0; i <= (int)a.size(); ++i) {
                int x = (i == (int)a.size()) ? 0 : a[i];
                while (!st.empty() && a[st.back()] > x) {
                    int H = a[st.back()]; st.pop_back();
                    int L = st.empty() ? -1 : st.back();
                    best = max(best, H * (i - L - 1));
                }
                st.push_back(i);
            }
            return best;
        };

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j)
                h[j] = (matrix[i][j] == '1') ? h[j] + 1 : 0;
            ans = max(ans, max_histogram(h));
        }
        return ans;
    }
};
