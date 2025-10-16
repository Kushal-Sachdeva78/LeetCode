#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + skill[i];
        long long total = pref[n], t = 0;
        for (int j = 0; j+1 < m; ++j) {
            long long a = mana[j], b = mana[j+1], best = LLONG_MIN, d = a - b;
            for (int i = 0; i < n; ++i) {
                long long v = a*1LL*skill[i] + d*pref[i];
                if (v > best) best = v;
            }
            t += best;
        }
        return t + mana.back()*1LL*total;
    }
};
