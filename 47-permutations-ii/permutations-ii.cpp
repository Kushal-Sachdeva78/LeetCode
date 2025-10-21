#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<int> cur; cur.reserve(n);
        vector<int> used(n, 0);
        vector<vector<int>> ans;
        function<void()> dfs = [&]() {
            if ((int)cur.size() == n) { ans.push_back(cur); return; }
            for (int i = 0; i < n; ++i) {
                if (used[i]) continue;
                if (i && a[i] == a[i-1] && !used[i-1]) continue;
                used[i] = 1; cur.push_back(a[i]);
                dfs();
                cur.pop_back(); used[i] = 0;
            }
        };
        dfs();
        return ans;
    }
};
