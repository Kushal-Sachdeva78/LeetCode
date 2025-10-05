class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // last position seen for each ASCII char; -1 = unseen
        vector<int> last(256, -1);
        int best = 0, left = 0;                 // window = [left, i]
        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char c = s[i];
            if (last[c] >= left) left = last[c] + 1; // move left past duplicate
            last[c] = i;
            best = max(best, i - left + 1);
        }
        return best;
    }
};
