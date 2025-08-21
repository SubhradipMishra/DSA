class Solution {
public:
    int m, n;
    vector<vector<int>> memo;

    // Helper to count number of submatrices starting at (i, j)
    int countFrom(int i, int j, const vector<vector<int>>& mat) {
        if (i >= m || j >= n) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int width = 0, count = 0;

        // Try to expand downward starting at (i, j)
        for (int row = i; row < m; ++row) {
            if (mat[row][j] == 0) break;

            int currWidth = 0;
            for (int col = j; col < n && mat[row][col] == 1; ++col)
                currWidth++;

            width = (row == i) ? currWidth : min(width, currWidth);
            count += width;
        }

        return memo[i][j] = count;
    }

    int numSubmat(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        memo.assign(m, vector<int>(n, -1));
        int total = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 1)
                    total += countFrom(i, j, mat);

        return total;
    }
};
