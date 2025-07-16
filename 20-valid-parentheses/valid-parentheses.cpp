class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 2)  return false ;
        stack<char>st ;
        for(int  i = 0 ; i < s.size()  ; i++){
            if (st.empty()) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    st.push(s[i]);
                }
                else return false; 
            }
            else{
               if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]) ; 
            else if(s[i] == ')' ){
                if(st.top() == '(') st.pop() ;
                else return false ;  
            }
            else if(s[i] == '}' ){
                if(st.top() == '{') st.pop() ; 
               else  return false  ;
            }
            else if(s[i] == ']' ){
                if(st.top() == '[') st.pop() ; 
                 else  return false  ;
            }
            }
            
        }

        return st.empty(); 
    }
};