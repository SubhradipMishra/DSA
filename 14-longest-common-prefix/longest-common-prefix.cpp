class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin()  , strs.end()) ; 
        string first = strs[0] ; 
        string last =  strs[strs.size()-1];
        int  n1 = first.size(); 
        int  n2 = last.size() ;
        string ans = "";
        for(int i = 0 ; i < min(n1,n2) ; i++){
          if(first[i] == last[i] ) ans+=first[i] ;
          else  break ; 
        }

        return ans;
    }
};