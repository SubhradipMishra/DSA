class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum  = n*(n+1)/2 ;
        int x = 0 ; 
        for(int i  = 1 ; i <= n ; i++){
           if(i%m == 0  ) x+=i; 

        }

        int y = sum-x;
        int ans = y - x ; 
        return ans; 
    }
};