class Solution {
public:
    void helper(vector<int>& nums ,  vector<vector<int>>& ans , vector<int> v , int idx ){
        ans.push_back(v) ;
        for(int  i= idx ; i < nums.size() ; i++) {
           if(i > idx && nums[i-1] ==  nums[i] ) continue ;
           v.push_back(nums[i]) ;
           helper(nums,ans , v,i+1);
           v.pop_back() ;

        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        vector<vector<int>> ans  ; 
        vector<int> v ; 
        helper(nums,ans,v , 0)  ;
        return ans ; 
    }
};