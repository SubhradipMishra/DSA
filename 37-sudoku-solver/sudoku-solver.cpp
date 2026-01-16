class Solution {
public:
    bool check(int num, vector<vector<char>>& board, int i, int j) {
        char ch = '0' + num;

        for (int col = 0; col < 9; col++) {
            if (board[i][col] == ch) return false;
        }

        for (int row = 0; row < 9; row++) {
            if (board[row][j] == ch) return false;
        }

        int sr = (i / 3) * 3;
        int sc = (j / 3) * 3;

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (board[sr + a][sc + b] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(int i, int j, vector<vector<char>>& board) {
        if (i == 9) return true;
        if (j == 9) return solve(i + 1, 0, board);

        if (board[i][j] != '.')
            return solve(i, j + 1, board);

        for (int num = 1; num <= 9; num++) {
            if (check(num, board, i, j)) {
                board[i][j] = '0' + num;

                if (solve(i, j + 1, board))
                    return true;

                board[i][j] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};
