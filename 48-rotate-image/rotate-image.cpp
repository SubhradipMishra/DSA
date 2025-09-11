class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() ; 


        // transpose the matrix

        for(int i   = 0 ; i < n  ;i++){
            for(int j = i ; j < n ; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp ; 

            }
        }


        for(int  i =  0 ; i  < n  ;i++){
            int st = 0 ; 
            int la = n-1;
            while(st<=la){
                int temp = matrix[i][st];
                matrix[i][st] = matrix[i][la];
                matrix[i][la] = temp ;
                st++;
                la--;
            }
        }


    }
};