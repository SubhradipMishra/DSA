class Solution {
public:
    int searchInsert(vector<int>& nums, int k) {
        int  n  = nums.size() ; 
        int lo =  0 ; 
        int hi = n-1 ; 
        int ans = n ; 
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            // if(nums[mid] == k )  return mid ; 
             if(nums[mid] < k  ) lo = mid+1;
            else{
                ans = mid ; 
                hi = mid-1; 
            }
        }

        return ans ; 
    }
};