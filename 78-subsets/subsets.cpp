class Solution {
public:

   void helper(vector<int>& arr , vector<vector<int>>& ans , vector<int>& v , int idx){
    if(idx ==  arr.size()){
        ans.push_back(v) ; 

        return  ; 
    }

    v.push_back(arr[idx]) ;
    helper(arr , ans,  v , idx +1 );
    v.pop_back() ; 
     helper(arr , ans,  v , idx +1 );
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans ; 
        vector<int>v ; 

        helper(nums , ans , v , 0 ) ; 

        return ans;  
    }
};