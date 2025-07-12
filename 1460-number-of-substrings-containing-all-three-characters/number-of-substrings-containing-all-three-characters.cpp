class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0 ;
        string str = "abc" ; 
        unordered_map<char,int>mp ;
        for(int i  =  0 ; i < str.size() ; i++ ){
            mp[str[i]] = -1 ;
        }

        for(int  i = 0  ; i < s.size() ; i++ ) {
            mp[s[i]] = i  ; 
            if(mp['a'] != -1 && mp['b'] != -1 && mp['c'] != -1)
            count =  count +  min({mp['a'] , mp['b'] , mp['c']}) +1  ;
        }


        return count ;

    }
};