class Solution {
public:
    void solve(vector<int>& arr , int k ,  int idx ,  vector<int>v , vector<vector<int>>& ans){
          if(idx == arr.size()){
            if( k == 0 ){

              ans.push_back(v);
            }

            return ; 
          }

          if(arr[idx] <= k ){
            
            v.push_back(arr[idx]) ; 
            solve(arr , k-arr[idx] , idx , v,ans);
            v.pop_back() ;
          }
             solve(arr , k , idx + 1 , v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>>ans; 
        vector<int>v  ; 
        solve(arr,  k  , 0 , v,ans);
        return ans ; 
    }
};