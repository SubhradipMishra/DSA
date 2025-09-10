class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end()) ; 
        int n = strs.size() ; 
        string first = strs[0] ; 
        string last = strs[n-1] ; 
        string ans = "" ;
        int n1 = first.size() ; 
        int n2 = last.size() ; 

        for(int i =  0 ; i < min(n1,n2) ; i++){
            if(first[i] == last[i] ) ans+=first[i] ;
            else break; 
        }


        return ans ; 

       
    }
};