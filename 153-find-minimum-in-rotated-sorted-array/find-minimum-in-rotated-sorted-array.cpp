class Solution {
public:
    int findMin(vector<int>& nums) {
        int n =  nums.size() ; 
        int lo =  0 ;
        int hi = n-1;
        while(lo <= hi ){
            if(nums[lo] <= nums[hi] ) return nums[lo ];
            int mid = lo + (hi-lo)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            if(nums[mid] <= nums[next ]&& nums[mid] <=  nums[prev]) return nums[mid]  ; 
            else if(nums[lo] <= nums[mid]) lo  = mid +1;
            else hi  = mid-1;

        }

        return -1;

    }
};