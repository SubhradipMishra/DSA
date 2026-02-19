class Solution {
public:

    void helper(vector<int>& arr , vector<vector<int>>& ans , vector<int>& v , int k , int idx){
        if(k == 0 ){
            ans.push_back(v) ;
            return ; 
        }

        for(int i =  idx ; i <arr.size() ; i++ ){
            if(arr[i] >  k ) break;
            if(i > idx && arr[i] == arr[i-1] ) continue ; 
            v.push_back(arr[i]);
            helper(arr , ans , v , k - arr[i] , i+1);
            v.pop_back() ; 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
      sort(arr.begin() , arr.end()) ; 
      int n = arr.size() ; 
      vector<vector<int>>ans ; 
      vector<int>v ; 
      helper(arr,  ans, v , k , 0) ; 
      return ans ;    
    }
};