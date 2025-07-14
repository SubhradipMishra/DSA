class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size() ; 
        int i =   0 ;
        int j  = 0 ; 
        int maxF = 0 ; 
        int maxLen = 0 ; 
        map<char,int>mp ;
        while(j  <  n ) {
            mp[s[j]]++ ;
            maxF = max(maxF , mp[s[j]]);
            while((j- i +1 )- maxF > k ) {
                mp[s[i]]-- ;
                if(mp[s[i]] == 0 ) mp.erase(s[i]) ;
                maxF = 0 ;
                for(auto it :  mp){
                    maxF =  max(maxF , it.second) ; 
                }
                i++ ;
            }
             maxLen = max(maxLen , j  - i +1) ;
            j++ ; 
        }

        return maxLen ; 
    }
};