class Solution {
public:
    int mySqrt(int x) {
        int low = 1 ; 
        int high =  x/2 ; 
      
        if(x==0 or  x ==  1) return  x;
          while(low <=  high ) {
            int mid = low + (high-low)/2 ; 
            if(mid ==  x/mid )  return mid ; 
             else if(mid > x / mid) high = mid - 1;
             else low = mid+1 ; 
          }

          return high ; 
    }
};