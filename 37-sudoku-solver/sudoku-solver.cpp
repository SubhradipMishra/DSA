#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == ch) return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return helper(board, row + 1, 0);
        if (board[row][col] != '.') return helper(board, row, col + 1);

        for (char ch = '1'; ch <= '9'; ch++) {
            if (isSafe(board, row, col, ch)) {
                board[row][col] = ch;
                if (helper(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
