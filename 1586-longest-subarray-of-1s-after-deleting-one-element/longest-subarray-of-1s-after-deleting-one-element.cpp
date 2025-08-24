class Solution {
public:
   
    int longestSubarray(vector<int>& nums) {
         int zerocount  = 0 ;
         int n = nums.size() ; 
         int i = 0; 
         int j = 0 ; 
         int maxLen = -1 ;
         while(j < n ){
            if(nums[j] == 0 ) zerocount++ ; 
            while(zerocount > 1) {
                if(nums[i] == 0 ) zerocount--;
            i++ ; 
            }

            maxLen = max(maxLen , j-i);
            j++; 
         }

         return maxLen ; 
    }
};