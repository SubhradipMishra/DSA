class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length()) return s;

    string result;
    int cycleLen = 2 * numRows - 2;  // Full cycle length

    for(int row = 0; row < numRows; row++) {
        for(int i = row; i < s.length(); i += cycleLen) {
            // Character in the vertical part of the zigzag
            result += s[i];

            // Character in the diagonal part (for middle rows only)
            int diagIndex = i + cycleLen - 2*row;
            if(row != 0 && row != numRows-1 && diagIndex < s.length())
                result += s[diagIndex];
        }
    }

    return result;
    }
};