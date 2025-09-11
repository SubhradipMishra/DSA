class Solution {
public:
    int totalFruit(vector<int>& s) {
        int n = s.size();
        int i = 0 ; 
        int j = 0 ;
        int maxLen = 0  ;
        int k = 2 ; 
        unordered_map<int,int>mp ; 
        while(j < n){
          mp[s[j]]++ ; 
          while(mp.size() > k ){
            mp[s[i]]--;
            if(mp[s[i]] == 0 ) mp.erase(s[i]);
            i++ ;
          }
          maxLen = max(maxLen , j-i+1);
          j++ ;
        }
        return maxLen ; 
    }
};