#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string a, string b) {
        int n = a.size(), m = b.size();
        vector<int> res(n + m, 0);
        for (int i = n - 1; i >= 0; --i)
            for (int j = m - 1; j >= 0; --j)
                res[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        for (int i = n + m - 1; i > 0; --i) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
        int i = 0;
        while (i < n + m - 1 && res[i] == 0) ++i;
        string s;
        for (; i < n + m; ++i) s.push_back(res[i] + '0');
        return s;
    }
};
