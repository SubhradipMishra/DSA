class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size() ; 
        int maxi =  0 ; 
        stack<int>st ; 
        for(int i =   0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] >  arr[i]) {

                int ele = arr[st.top()] ;
                st.pop() ;
                int pse = st.empty() ? -1 :st.top() ;
                int nse = i ;
                maxi = max(maxi , ele * (nse-pse-1)) ;
            }
            st.push(i) ;
        }
        while(!st.empty() ){
            int ele = arr[st.top()] ;
            st.pop() ;
            int nse  =  n ; 
            int pse = st.empty() ? -1 : st.top() ; 
            maxi = max(maxi , ele * (nse-pse-1)) ;
        }

        return maxi ; 
    }
};