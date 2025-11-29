class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Base case: if out of bounds or current cell is water ('0')
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;

        // Mark the cell as visited
        grid[i][j] = '0';

        // Visit all 4 adjacent directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);  // sink the island
                    count++;          // increment the number of islands
                }
            }
        }

        return count;
    }
};
