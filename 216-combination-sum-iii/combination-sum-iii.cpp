class Solution {
public:

    void helper(vector<int>arr , vector<vector<int>>& ans , vector<int>& v , int k , int sum , int idx  ){

        
        if(idx == arr.size()){
            if(sum == 0 &&  v.size() ==  k ){
                ans.push_back(v) ; 
                
            }

            return; 
        }

        if(sum < 0 ) return  ; 


        if(arr[idx] <= sum){
            v.push_back(arr[idx]) ; 
            helper(arr  , ans , v , k , sum - arr[idx]  , idx +1 )  ; 
            v.pop_back() ; 

        } 

        helper(arr  , ans , v , k , sum , idx +1 )  ; 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr  ;
        for(int i  = 1 ; i <= 9 ; i++){
            arr.push_back(i) ; 
        }

       vector<vector<int>>ans ; 
       vector<int>v ; 

       helper(arr , ans , v  , k , n , 0) ; 

       return ans;         
    }
};