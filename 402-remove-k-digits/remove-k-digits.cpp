class Solution {
public:
    string removeKdigits(string num, int k) {
        int n  = num.size() ; 
        stack<char>st ; 
        for(int i  =  0 ;  i  < n  ; i++){
            while(!st.empty() && k > 0 && (st.top()-'0') > (num[i]-'0')) {
                st.pop(); 
                k-- ; 
            }
            st.push(num[i]) ;
        }

        while(k != 0 && !st.empty()){
            st.pop() ;
            k-- ;
        }


        // creat the answer from stack by add element of stack ; 

        string res = "";
        while(!st.empty()){
          res+=st.top(); 
          st.pop();  
        }

        // if the number has leading zeros now the zeros has in the back of the res so remove them

        while(res.size() != 0 && res.back() == '0'){
            res.pop_back() ; 
        }

        // reverse the res because we get it from stack

        reverse(res.begin() , res.end()) ; 

        if(res.size() == 0  ) return "0";
        else return res ; 
 
    }
};