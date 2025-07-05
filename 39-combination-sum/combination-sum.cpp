class Solution {
public:
    void helper(vector<int>& arr, vector<vector<int>>& ans ,vector<int>ds , int idx , int k  ){
        if(idx ==  arr.size()){
            if( k == 0 ){
                ans.push_back(ds);
            }

            return ;
        }
        if(arr[idx] <= k){
        ds.push_back(arr[idx]) ;
        helper(arr,ans,ds,idx ,k-arr[idx]) ; 
        ds.pop_back() ;
        }
        helper(arr,ans,ds,idx+1,k);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>>ans ; 
        vector<int>ds ; 

        helper(arr,ans ,ds,0,k) ; 

        return ans; 

    }
};