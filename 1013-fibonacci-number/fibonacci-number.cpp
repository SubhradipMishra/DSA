class Solution {
public:
    int fib(int n) {
  
      int prev2 = 0 ;
      int prev = 1 ;
      for(int  i =2 ; i<= n ;i++) {
        int curri =prev2 + prev ; 
          prev2 = prev  ; 
          prev = curri; 
      }  

      return n == 0 ? prev2 : prev ; 
    }
};