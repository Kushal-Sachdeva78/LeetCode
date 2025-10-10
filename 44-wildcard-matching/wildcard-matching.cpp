#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= m; ++j)
            if (p[j - 1] == '*') dp[j] = dp[j - 1];

        for (int i = 1; i <= n; ++i) {
            vector<int> newdp(m + 1, 0);
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                    newdp[j] = dp[j - 1];
                else if (p[j - 1] == '*')
                    newdp[j] = dp[j] || newdp[j - 1];
            }
            dp = newdp;
        }
        return dp[m];
    }
};
