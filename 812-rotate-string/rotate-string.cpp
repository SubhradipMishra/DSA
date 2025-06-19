class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())  return false ; 
        s = s+s ; 
        int x = s.find(goal) ; 
        if(x>=0 && x<= s.size()-1) return true  ;
        else return false ;  
    }
};