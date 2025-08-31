class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =  s.length();
        int  i = 0 ; 
        int  j = 0 ; 
        int maxLen = 0 ; 
        map<char,int>mp ;
        while(j < n){
            if(mp.find(s[j]) ==  mp.end()){
                mp[s[j]] = j ; 

            }
            else{
                i = max(i,mp[s[j]]+1 ) ;
                mp[s[j]] = j  ;
            }

               maxLen = max(maxLen , j - i +1  ) ;
               j++ ;
        }

        return maxLen ; 

    }
};