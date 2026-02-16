class Solution {
public:
    void findCombination(vector<int>& arr , vector<int>v ,  vector<vector<int>>& ans , int  i , int k  ){
        if(i == arr.size()){
            if(k == 0 ) ans.push_back(v) ; 
            return ; 
        }

        // take case
        
        if(k >= arr[i]) {
            v.push_back(arr[i]) ; 
            findCombination(arr , v , ans, i, k - arr[i]) ; 
            v.pop_back(); 
        }
        findCombination(arr , v , ans, i+1, k ) ; 

        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        
        int n = arr.size() ; 
        vector<vector<int>>ans ;
        vector<int>v ;  
        findCombination(arr , v ,  ans, 0 ,k );

        return ans  ; 
    }
};