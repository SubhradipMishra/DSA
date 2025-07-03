class Solution {
public:
    string getNew(string ans ){
        string res = "" ; 
        for(int i = 0 ; i <ans.size() ;i++ ){
            res+= ans[i] + 1;
        }

        return res ;
    }
    char kthCharacter(int k) {
        string ans = "a" ;
        while(ans.size()<k){ 
            string s  = getNew(ans) ;
            ans+= s ;
        }
        return  ans[k-1] ;
    }
};