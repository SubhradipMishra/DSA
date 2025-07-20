class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st; 
        int n = arr.size(); 
        int maxi = 0; 
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int el = st.top(); // index
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, arr[el] * (nse - pse - 1)); // ✅ Use arr[el]
            }
            st.push(i);
        }

        while (!st.empty()) {
            int el = st.top(); // index
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top(); // ✅ Needed here too
            maxi = max(maxi, arr[el] * (nse - pse - 1)); // ✅ Use arr[el]
        }

        return maxi;
    }
};
