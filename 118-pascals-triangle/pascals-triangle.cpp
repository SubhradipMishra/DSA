class Solution {
public:
     vector<int>generateRow(int row){
        long long ans =  1 ; 
        vector<int> res ; 
        res.push_back(ans) ; 
        for(int col  =  1 ; col < row ; col++)
        {
            ans = ans *(row-col) ;
            ans = ans/(col) ; 
            res.push_back(ans); 
        }
        return res; 
     }
    vector<vector<int>> generate(int n) {
          vector<vector<int>>ans ; 
          for(int i  = 1 ; i <=  n ; i++){
           ans.push_back(generateRow(i)) ;

        
          }

          return ans ; 
    }
};