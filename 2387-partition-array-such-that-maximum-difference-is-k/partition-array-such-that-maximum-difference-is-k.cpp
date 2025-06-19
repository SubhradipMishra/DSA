class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin()   , nums.end()) ; 
        int count = 0 ; 
        int n = nums.size()  ; 
        int i  =  0 ; 
        while(i < n ){
            int start  = nums[i] ; 
            while( i  <  n && nums[i] - start <= k) {
                i++;
            }
            count++;
        }

        return count; 
    }
};