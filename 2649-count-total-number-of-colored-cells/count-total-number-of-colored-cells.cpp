class Solution {
public:
    long long coloredCells(int n) {
        long long result = 1; 
        long long add = 4; 

        for (int i = 2; i <= n; i++) {
            result += add;
            add += 4;
        }

        return result;
    }
};
