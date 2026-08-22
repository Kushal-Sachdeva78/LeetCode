class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (s[0] == '0')
            return 0;

        int prev2 = 1;  // dp[i-2]
        int prev1 = 1;  // dp[i-1]

        for (int i = 1; i < n; i++) {
            int current = 0;

            // Decode s[i] as a single digit
            if (s[i] != '0') {
                current += prev1;
            }

            // Decode s[i-1] + s[i] as a two-digit number
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');

            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};