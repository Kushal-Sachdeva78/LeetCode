class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A); 
        int m = A.size(), n = B.size();
        int totalLeft = (m + n + 1) / 2;
        int l = 0, r = m;

        while (l <= r) {
            int i = (l + r) / 2;         // cut in A
            int j = totalLeft - i;       // cut in B

            int Aleft  = (i == 0) ? INT_MIN : A[i - 1];
            int Aright = (i == m) ? INT_MAX : A[i];
            int Bleft  = (j == 0) ? INT_MIN : B[j - 1];
            int Bright = (j == n) ? INT_MAX : B[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 0)
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                else
                    return max(Aleft, Bleft);
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return 0.0; // unreachable
    }
};
