class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long a = labs(dividend), b = labs(divisor), res = 0;
        while (a >= b) {
            long t = b, m = 1;
            while (a >= (t << 1)) {
                t <<= 1;
                m <<= 1;
            }
            a -= t;
            res += m;
        }
        return (dividend > 0) == (divisor > 0) ? res : -res;
    }
};
