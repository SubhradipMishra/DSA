class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0 ||  n  < 0 ) return false  ;
        if (n== 1) return true; 
        
    if (n > 0 && n % 3 == 0) {
            while (n != 1) {
                if (n % 3 != 0) return false; // If n is not a power of two
                n = n / 3;
            }
            return true;
        }
        
            return false; 
    }
};