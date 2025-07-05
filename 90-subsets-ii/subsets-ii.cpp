class Solution {
public:
    void helper(vector<int>& nums , vector<vector<int>>& ans , vector<int>ds  , int idx){
        ans.push_back(ds); 
        for(int i =  idx  ; i < nums.size() ; i++){
          if(i >idx && nums[i] == nums[i-1]) continue;
          ds.push_back(nums[i]) ; 
          helper(nums,ans,ds,i+1) ;
          ds.pop_back()  ;   
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ; 
        vector<vector<int>>ans ; 
        vector<int>ds ;
        helper(nums,ans,ds,0);
        return ans;
    }
};