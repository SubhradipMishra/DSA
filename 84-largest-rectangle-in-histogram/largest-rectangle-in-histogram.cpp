class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
         int n = arr.size() ; 
         stack<int>st ; 
         int maxi =  0 ;
         for(int i   =  0 ; i  < n  ; i++){
            while(!st.empty() && arr[st.top()]  > arr[i] ){
                int el =  arr[st.top()] ; 
                st.pop() ;
                int nse =  i ;
                int pse = st.empty() ? -1 : st.top() ;
                maxi  = max(maxi , el*(nse-pse-1)) ;

            }
            st.push(i) ;
         }

         while(!st.empty()){
            int el =arr[st.top()] ;
            st.pop() ;
            int nse = n ;
            int pse  = st.empty() ?  -1 : st.top() ;
             maxi  = max(maxi , el*(nse-pse-1)) ;

            
         }

         return maxi ; 
    }

};