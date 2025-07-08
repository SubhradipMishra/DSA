class Solution {
private:
    int countSetBits(long long n) {
        int count = 0;
        while (n) {
            if (n & 1) count++;
            n = n >> 1;
        }
        return count;
    }

public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // Add this to handle negative or 0 input
        int noOfSetBits = countSetBits(n);
        return noOfSetBits == 1;
    }
};
