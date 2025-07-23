class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        if (x > y) {
            return removePairs(s, 'a', 'b', x) + removePairs(s, 'b', 'a', y);
        } else {
            return removePairs(s, 'b', 'a', y) + removePairs(s, 'a', 'b', x);
        }
    }

private:
    int removePairs(string& s, char first, char second, int gain) {
        stack<char> st;
        string temp = "";
        int score = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                score += gain;
            } else {
                st.push(c);
            }
        }

     
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;

        return score;
    }
};
