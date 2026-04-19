class Solution {
public:
int n , m ;

    int dfs(vector<vector<int>>& grid , int i ,  int j )
    {
        if(i < 0  || j < 0 || i >= n || j>=m || grid[i][j] == 0  ) return 0 ; 

        grid[i][j] = 0 ; 
    

        return 1 + dfs(grid , i  , j +1  )+dfs(grid , i ,j-1) + dfs(grid,  i + 1 , j )  +  dfs(grid , i-1,j) ; 

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans =  0 ; 
         n = grid.size() ; 
         m = grid[0].size() ; 

        for(int i = 0 ;i < n ; i++){
            for(int j =0 ;  j < m  ; j++){
                if(grid[i][j] ==  1)
                ans = max(ans , dfs(grid,   i , j ))  ; 
            }
        }


        return ans ; 
    }
};