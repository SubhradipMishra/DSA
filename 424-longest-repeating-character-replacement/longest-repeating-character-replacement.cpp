class Solution {
public:
    int characterReplacement(string s, int k) {
       int n  = s.size() ; 
       int maxF = 0 ; 
       unordered_map<char,int>mp ; 
       int maxLen =  0;
       int i =  0; 
       int j =  0 ;
       while( j < n){
         mp[s[j]]++ ; 
         maxF = max(maxF , mp[s[j]]) ;
         int len = j - i + 1 ; 
         if( len - maxF > k ){
            mp[s[i]]-- ; 
            if(mp[s[i]] == 0 ) mp.erase(s[i]) ; 
            i++;
            len = j - i  +1 ;
         } 

         maxLen = max(maxLen , len) ; 
         j++ ; 

       } 

       return maxLen ;  
    }
};