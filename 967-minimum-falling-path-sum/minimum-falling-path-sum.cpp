class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(matrix[0]); // Initialize with the first row

        vector<int> cur(m, 0);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if (j - 1 >= 0) ld += prev[j - 1];
                else ld += 1e8;  // Large value to avoid selecting invalid paths
                
                int rd = matrix[i][j];
                if (j + 1 < m) rd += prev[j + 1];
                else rd += 1e8;

                cur[j] = min(u, min(ld, rd));
            }
            prev = cur;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
