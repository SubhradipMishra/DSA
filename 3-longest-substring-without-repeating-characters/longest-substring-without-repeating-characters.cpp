class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =  0 ;
        int j =  0  ;
        int n = s.size() ; 
        int ans =  0 ; 
        unordered_map<char,int> mp; 

        while(j < n){
            if(mp.find(s[j]) != mp.end()){
             i = max(i, mp[s[j]] + 1); 
                mp.erase(s[j]) ; 
                
            }
            mp[s[j]] = j ; 
            ans = max(j - i + 1 , ans)   ;
            j++ ;
        }

        return ans ; 
    }
};