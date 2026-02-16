class Solution {
public:

    void helper(vector<int>& arr, vector<vector<int>>& ans , vector<int>v , vector<bool>used  ){
        if(v.size() == arr.size() ){
            ans.push_back(v) ; 
            return ; 
        }
    
        for(int i  =  0 ; i <  arr.size() ; i++){
            if(used[i] == true) continue;


            used[i] = true; 
            v.push_back(arr[i]) ; 


            helper(arr , ans, v, used ) ; 
            
            v.pop_back() ; 
            used[i] = false; 
         }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans ;
        vector<int>v ;  
        vector<bool>used(nums.size() , false) ;
        helper(nums,ans,v,used );

        return ans ; 
    }
};