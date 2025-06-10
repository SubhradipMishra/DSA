class Solution {
public:
    int bs(int lo , int hi ,vector<int>& nums, int k ){
        while(lo <= hi ){
            int mid = lo + (hi-lo)/2 ;
            if(nums[mid] == k ) return mid ; 
            else if(nums[mid]  < k  ) lo = mid + 1 ;
            else hi = mid -1 ; 
        }
        return -1;
    }
    int minIdx(vector<int>& nums){
        int lo =  0 ;
        int  n = nums.size() ;
        int hi = n - 1 ; 
        while(lo <= hi ){
            if(nums[lo] <= nums[hi] )  return lo ; 
            int mid = lo + (hi - lo )/2; 
            int next = ( mid +1 ) % n ; 
            int prev = (mid -1 + n ) % n ;
            if(nums[mid] < nums[prev] && nums[mid] <  nums[next] ) return mid ; 
            else if(nums[mid] >=  nums[lo]) lo = mid + 1; 
            else hi  =  mid-1; 
        }

        return -1;
        
    }
    int search(vector<int>& nums, int k) {
        int min_idx = minIdx(nums);
        int n = nums.size() ; 
        int ans1 = bs(0,min_idx-1,nums,k)  ;
        int ans2 = bs(min_idx,n-1,nums,k)  ;
        if(ans1 == -1) return ans2 ;
       else if(ans2 == -1) return ans1 ;
       else return -1;

    }
};