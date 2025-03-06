class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n   =  grid.size() ; 
        int x =n*n ; 
         unordered_map<int,int> mp ; 
         for(int i   = 0 ; i  <  n ; i++ ) {
            for(int j  = 0  ; j   <   n ; j++ ) {
                mp[grid[i][j]]++  ; 
            }
         }

         vector<int> ans(2) ; 

         for(int  i = 1 ; i<= x; i++){
            if(mp.find(i) == mp.end()) ans[1] = i; 
            else {
                if(mp[i]>1)  ans[0] = i ; 
            }
         }


         return ans ; 
    }
};