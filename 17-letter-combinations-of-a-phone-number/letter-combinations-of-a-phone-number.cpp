#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> res;
        string curr;

        function<void(int)> backtrack = [&](int idx) {
            if (idx == digits.size()) {
                res.push_back(curr);
                return;
            }
            for (char c : mapping[digits[idx] - '0']) {
                curr.push_back(c);
                backtrack(idx + 1);
                curr.pop_back();
            }
        };

        backtrack(0);
        return res;
    }
};
