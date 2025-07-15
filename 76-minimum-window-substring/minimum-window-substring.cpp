class Solution {
public:
    string minWindow(string s, string t) {
        int n =  s.size() ;
        int m =  t.size() ;
        int i = 0 ; 
        int j = 0;
        int count = 0 ;
        int sIdx = -1; 
        int minLen =  INT_MAX ; 
        map<char,int>mp ;
        for(char ch : t) mp[ch]++; 
        while( j < n ){
        if( mp[s[j]] > 0 ) count++ ;
        mp[s[j]]--;
         while(count == m ) 
        {
          if(minLen > j  - i +  1 ) {
            sIdx = i ; 
            minLen = j  - i +  1  ;
          }
          mp[s[i]]++;
          if (mp[s[i]] > 0) {
                    count--;
                }
                i++;
          
        }

        j++ ;
        }
        return sIdx == -1 ?  "" : s.substr(sIdx , minLen);
    }
};