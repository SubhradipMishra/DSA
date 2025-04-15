class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1) ;
        int n = s.size() ;
        int  i =  0 ; 
        int j =  0 ;
         int maxLen = 0; 
        while(j < n){
            if(mp[s[j]]!=-1){
                i = max(mp[s[j]]+1 , i ) ;
            }
          
                mp[s[j]] =  j ; 
                maxLen =  max(maxLen , j-i+1 ) ;
                j++;
            
        }

        return maxLen ; 
    }
};