class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int,int)> dfs = [&](int start, int remain) {
            if (remain == 0) { res.push_back(cur); return; }
            for (int i = start; i < (int)candidates.size(); ++i) {
                int v = candidates[i];
                if (v > remain) break;
                cur.push_back(v);
                dfs(i, remain - v);
                cur.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};
