class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i  = 0  ;
        int j  = 0 ; 
        int sum =  0; 
        int maxSum= 0 ; 
        int n = nums.size();
        unordered_map<int,int>mp;  
        while(j < n){
          if(mp.find(nums[j]) == mp.end()){
             sum+=nums[j] ;
             maxSum = max(maxSum ,sum) ; 
             mp[nums[j]]++ ; 
             j++ ; 
          }
          else{
             mp[nums[i]]--;
             sum-=nums[i] ;
             if(mp[nums[i]] == 0 ) mp.erase(nums[i]) ; 
             i++ ; 
          }
        }

        return maxSum ; 
    }
};