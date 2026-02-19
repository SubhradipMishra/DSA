class Solution {
private:
bool isPalindrome(int l , int r , string s){
    while(l < r ){
        if(s[l] != s[r]) return false;
    l++ ;
    r--;
    }

    return true; 
}
public:

   void solve(vector<vector<string>>& ans  , vector<string>& temp , string s , int idx){
    if(idx == s.size()){
        ans.push_back(temp) ; 
        return  ; 
    }

    for(int i   =  idx ; i < s.size() ; i++){
        if(isPalindrome(idx , i , s)){
            temp.push_back(s.substr(idx , i - idx  +1 )) ; 
            solve(ans, temp , s, i +1 ) ;
            temp.pop_back() ;
        }
    }
   }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans ; 
        int n = s.length() ; 
        vector<string>temp ; 
        solve(ans , temp , s , 0) ; 
        return ans ; 
    }
};