#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) return false;
        unordered_map<char,char> match{{')','('},{']','['},{'}','{'}};
        string st; st.reserve(s.size());
        for (char c : s) {
            if (c=='(' || c=='[' || c=='{') st.push_back(c);
            else {
                if (st.empty() || st.back() != match[c]) return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};
