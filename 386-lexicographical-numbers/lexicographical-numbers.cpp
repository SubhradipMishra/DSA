class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> st; 
        
       
        for (int i = 1; i <= n; i++) {
            st.push_back(to_string(i));
        }

   
        sort(st.begin(), st.end());

        
        vector<int> result;
        for (string s : st) {
            result.push_back(stoi(s));
        }

        return result;
    }
};
