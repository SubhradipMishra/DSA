class Solution {
public:
   void dfs(int sr , int sc , vector<vector<int>>& ans ,vector<vector<int>>& image,int initial_color, int delRow[] , int delCol[] , int newColor ){
    ans[sr][sc] = newColor ;
    int n = image.size() ;
    int m = image[0].size() ;
    for(int i =   0 ; i < 4 ; i++){
        int newRow = delRow[i] +  sr;
        int newCol = delCol[i] +  sc ;

        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && ans[newRow][newCol] != newColor && ans[newRow][newCol] == initial_color  )
        dfs(newRow, newCol , ans, image , initial_color ,  delRow, delCol , newColor) ;

    }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int initial_color = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        dfs(sr , sc , ans , image, initial_color ,delRow,  delCol,color );

        return ans ; 
    }
};