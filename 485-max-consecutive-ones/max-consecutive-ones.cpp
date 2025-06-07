class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     int n = nums.size() ; 
     int  i = 0; 
     int  j = 0 ;
     int maxLen =  0 ; 
      while( j <  n ){
        if(nums[j] == 1 ) {
             j++  ;
             maxLen = max(maxLen  , j - i);  
        }
        else {
            j++ ; 
             i = j  ; 
        }
      } 

      return maxLen ;  
    }
};