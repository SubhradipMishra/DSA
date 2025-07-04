class Solution {
public:
    void helper(vector<int>& nums , vector<vector<int>>& ans , vector<int>v  , int idx){
      if(idx ==  nums.size()) {
        ans.push_back(v);
        return  ;
      }
      //we follow take and not take approch 
      helper(nums,  ans , v,idx+1) ; 
      v.push_back(nums[idx]) ; 
      helper(nums,  ans , v,idx+1) ; 

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n  =  nums.size() ; 
        vector<vector<int>> ans ; 
        vector<int>v ; 
        helper(nums, ans, v , 0) ; 


        return ans ; 
    }
};