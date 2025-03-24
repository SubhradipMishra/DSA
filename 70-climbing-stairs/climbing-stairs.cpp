class Solution {
public:
   
    int climbStairs(int n) {
      vector<int>dp(n+1,-1) ;
      int p2 = 1 ; 
      int p1  = 1;
       for(int i = 2 ;i<=n ;i++){
        int ci = p2 + p1; 
        p2 =p1 ;
        p1 = ci  ;
       }

       return p1;
    }
};
