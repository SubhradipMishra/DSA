class Solution {
public:
    void helper(vector<int>& arr , vector<vector<int>>& ans , vector<int> ds , int idx , int k)  {
       if(k == 0 ){
        ans.push_back(ds) ;
        return; 
       }

       for(int i  = idx ;i<arr.size();i++ ){
        if(i > idx && arr[i] == arr[i-1]) continue ; 
        if(arr[i] >  k )  break ;

        ds.push_back(arr[i]) ; 
        helper(arr,ans,ds,i+1,k - arr[i]); 
        ds.pop_back() ;

       }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        sort(arr.begin() , arr.end()) ;  
        vector<vector<int>> ans ; 
        vector<int>ds; 
        helper(arr,ans,ds,0,k) ; 
        return ans  ; 
    }
};