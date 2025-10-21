#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0) return 1.0 / myPow(x, -n);
        double ans = 1;
        while (n) {
            if (n & 1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};
