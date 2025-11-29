class Solution {
public:

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int row, int col) {

        visited[row][col] = 1; 
        queue<pair<int,int>> q;

        int n = grid.size(); 
        int m = grid[0].size();
        
        q.push({row, col}); 
        
        while (!q.empty()) {
            int curr_row = q.front().first; 
            int curr_col = q.front().second; 
            q.pop(); 
             
            // YOUR STYLE — loops from -1 to 1
            for(int delRow = -1; delRow <= 1; delRow++){
                for(int delCol = -1; delCol <= 1; delCol++){

                    if(delRow == 0 && delCol == 0) continue;

                    int newRow = curr_row + delRow;
                    int newCol = curr_col + delCol;

                    // ❗ restrict to 4 directions only
                    if(abs(delRow) + abs(delCol) == 2) continue;   // remove diagonals

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {

                        // ❗ FIXED: comparison instead of assignment
                        if(visited[newRow][newCol] == 0 && grid[newRow][newCol] == '1') {
                            visited[newRow][newCol] = 1; 
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0)); 
        int count = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!visited[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(grid, visited, row, col);
                }
            }
        }
        return count;
    }
};
