class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n =  arr.size() ; 
        stack<int>st  ; 
        for(int i =  0 ; i <  n ; i++){
            // 1. If the element is positive then directly push it into the stack
            if(arr[i] >= 0  ) st.push(arr[i]) ; 

            // 2. if the element is negative

            // a. jab tak stack me element rahegi or stakc ki top element is postibve or astronoide ka absolute value se chota hoga tabtak usko  destroy korta rohega means pop() korega
          else{
            while(!st.empty() && st.top() > 0 && st.top() <  abs(arr[i]))  st.pop() ; 

        // b. dusra case ho sakta  stack khali na ho or uska jo top ka element o negative astronoide sr equal ho tob dono destroy ho jayega(pop())
           
            if(!st.empty() && st.top() == abs(arr[i])) st.pop() ; 

        // c. or ek case ho sakta stack khali ho yea top ke element negative to koi collison nahi hoga tab to ham us negative astronoyed ko bhi push kor sakta

           else if(st.empty() ||  st.top() < 0 )  st.push(arr[i]) ; 
            
         
            
        }
        }


        // ab hamko srif ans me store korn a ha lekin stack reverse me stor korega to reverse jaruri ha
         
         vector<int>ans; 

        while(!st.empty()){
            ans.push_back(st.top()) ;
            st.pop() ;
        }
        reverse(ans.begin() , ans.end()) ; 

        return ans; 
    }
};