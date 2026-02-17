class Solution {
public:
    bool rotateString(string s, string t) {
        if(s.size() != t.size()) return false ; 

        s = s + s ; 
        int x = s.find(t);

        if(x>=0 && x<= s.size()-1) return true  ;
        else return false ;  
    }
};