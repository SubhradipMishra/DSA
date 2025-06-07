class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int n  =  nums.size() ; 
       int count = 0 ; 
       int maxCount = -1 ;
       for(int  i = 0  ; i < n ; i++ ){
         if(nums[i] == 1 ) count++; 
         else {
            maxCount = max(count , maxCount) ;
            count = 0 ; 
         }

         maxCount = max(count, maxCount) ;
       }


        return maxCount ;
    }
};