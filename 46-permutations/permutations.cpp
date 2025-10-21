#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& a, int i) {
        if (i == a.size()) { res.push_back(a); return; }
        for (int j = i; j < a.size(); ++j) {
            swap(a[i], a[j]);
            dfs(a, i + 1);
            swap(a[i], a[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        dfs(a, 0);
        return res;
    }
};
