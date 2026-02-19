class Solution {
private:
  void helper(int n , string s , vector<string>& ans, int open , int close){
      if(close == n ){
        ans.push_back(s);
        return ; 
      }

      if(open < n ) helper(n,s+'(',ans ,open + 1 , close) ;
      if(close < open ) helper(n,s+')',ans ,open, close+1) ;

 }
public:

   
    vector<string> generateParenthesis(int n) {
        vector<string>ans ; 
        helper(n,"",ans,0,0) ; 

        return ans ; 
    }
};