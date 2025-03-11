class Solution {
public:
   void findComb(vector<int>& candidates ,vector<vector<int>>& ans , vector<int>ds ,int idx  , int target){
    if(idx ==candidates.size() ){
        if(target == 0 ) {
            ans.push_back(ds) ;
        }

        return  ; 
    }

    if(candidates[idx] <= target){
        ds.push_back(candidates[idx]) ; 
        findComb(candidates , ans , ds , idx , target -candidates[idx] );
        ds.pop_back() ;
    }

    findComb(candidates , ans , ds , idx+1 , target  );

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ; 
        vector<int>ds ; 
        findComb(candidates , ans , ds , 0 , target) ;

        return ans ; 
    }
};