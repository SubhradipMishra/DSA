class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1; // blocked start or end

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        q.push({0, 0});
        dist[0][0] = 1; // start distance is 1

        // 8 directions (including diagonals)
        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return dist[r][c]; // reached destination

            for (int i = 0; i < 8; i++) {
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 &&
                    dist[r][c] + 1 < dist[newRow][newCol]) {

                    dist[newRow][newCol] = dist[r][c] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return -1; 
    }
};
