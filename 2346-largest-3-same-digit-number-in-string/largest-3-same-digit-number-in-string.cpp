class Solution {
public:
    string largestGoodInteger(string num) {
        int maxNum = -1;
        int count = 1;

        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i - 1]) {
                count++;
                if (count == 3) {
                    int x = num[i] - '0';
                    maxNum = max(maxNum, x);
                }
            } else {
                count = 1;
            }
        }

        if (maxNum == -1) return "";
        string s = string(3, char('0' + maxNum));
        return s;
    }
};
