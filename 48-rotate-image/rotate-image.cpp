class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // transpose the matix

        for(int i  = 0 ; i <   m ; i++ ) {
            for(int j  = 0 ; j < i ; j++ ) {
                int temp = matrix[i][j] ;
                matrix[i][j] = matrix[j][i] ; 
                matrix[j][i] = temp;
            }
        }

        // rotate 

        for(int  i = 0 ;  i <   m  ; i++ ) {
            int j =  0 ; 
            int k = m-1;
            while(j < k ) {
               int temp = matrix[i][j] ; 
               matrix[i][j]= matrix[i][k]; 
               matrix[i][k] = temp ; 
               j++ ; 
               k-- ; 
            }
        }
    }
};