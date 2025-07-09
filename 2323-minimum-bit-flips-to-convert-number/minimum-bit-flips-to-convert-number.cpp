class Solution {
public:
    int countSetBits(int n ) {
  

    int  count = 0 ;
    while(n ){
        if( n & 1) count ++ ; 
        n = n>> 1 ;
    }

    return count ; 
        
    }
    int minBitFlips(int start, int goal) {
        
        int n =  start ^ goal ;

        return countSetBits(n)  ;


    }
};