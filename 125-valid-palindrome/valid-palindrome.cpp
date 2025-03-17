class Solution {
public:
    bool isPalindrome(string s) {
        // if(s.size() ==  1)  return true ; 
        string ans = "";
        for(int i   = 0 ; i  <  s.size();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                ans+=tolower(s[i]);
            } 
        }

        int i =  0 ; 
        int j = ans.size() -1;
        // cout << ans ; 
        if(ans.size() ==  1)  return true ; 
        while(i<=j){
            if(ans[i]!= ans[j] ) return false ; 
                i++ ; 
                j-- ;
        }
    

        return true ;
    }
};