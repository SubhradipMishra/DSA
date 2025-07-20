class Solution {
public:
    vector<int> findNextSmaller(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> ans(n); 
        stack<int> st; 
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop(); 
            ans[i] = st.empty() ? n : st.top(); 
            st.push(i); 
        }
        return ans; 
    }

    vector<int> findPreviousSmallerOrEqual(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> ans(n); 
        stack<int> st; 
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop(); 
            ans[i] = st.empty() ? -1 : st.top(); 
            st.push(i); 
        }
        return ans; 
    }

    long long findMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNextSmaller(arr); 
        vector<int> psee = findPreviousSmallerOrEqual(arr); 
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i]; 
            long long right = nse[i] - i; 
            total += left * right * (long long)arr[i];
        }

        return total;
    }

    vector<int> findNextGreater(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> ans(n); 
        stack<int> st; 
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop(); 
            ans[i] = st.empty() ? n : st.top(); 
            st.push(i); 
        }
        return ans; 
    }

    vector<int> findPreviousGreaterOrEqual(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> ans(n); 
        stack<int> st; 
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop(); 
            ans[i] = st.empty() ? -1 : st.top(); 
            st.push(i); 
        }
        return ans; 
    }

    long long findMax(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> nge = findNextGreater(arr); 
        vector<int> pgee = findPreviousGreaterOrEqual(arr); 
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i]; 
            long long right = nge[i] - i; 
            total += left * right * (long long)arr[i];
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return findMax(nums) - findMin(nums);
    }
};
