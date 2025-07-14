class Solution {
public:
    int find(vector<int>& nums, int k){
        int n = nums.size() ;
        int i = 0 ; 
        int j  =  0 ; 
        int count = 0 ; 
        map<int,int>mp ;
        while( j <  n ){
         mp[nums[j]]++ ;
         while(mp.size() > k ){
            mp[nums[i]]-- ;
            if(mp[nums[i]] == 0 )mp.erase(nums[i]);
            i++ ;
         }

         count += (j - i +1) ;
         j++ ;
        }

        return count ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = find(nums , k) - find(nums,k-1);
        return ans; 
    }
};