class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;  // Use long long to safely handle INT_MIN
        double ans = 1;

        // Make m positive for the loop
        if (m < 0) m = -m;

        while (m > 0) {
            if (m % 2 == 1) {
                ans *= x;
                m -= 1;
            } else {
                x *= x;
                m /= 2;
            }
        }

        if (n < 0) ans = 1.0 / ans;  // Keep this check exactly like your code
        return ans;
    }
};
