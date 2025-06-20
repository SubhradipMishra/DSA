class Solution {
public:
    int maxDepth(string s) {
       stack<char>open  ; 
       stack<char>close  ; 
       int ans = INT_MIN ; 
       for(int i =  0 ; i  < s.size()  ; i++ ) {
         int total = open.size() - close.size()  ;
           ans = max(total , ans ) ;
         if(s[i] == '(') open.push('(') ; 
         else if(s[i] ==')') close.push(')') ; 
        


       } 

       return ans ; 
    }
};