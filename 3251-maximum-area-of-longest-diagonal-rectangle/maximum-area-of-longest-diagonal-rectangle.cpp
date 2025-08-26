class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size(); 
        int ans = INT_MIN; 
        double sq = -1;   // to store max diagonal length (should be double)

        for(int i = 0; i < n; i++){
            int a = dimensions[i][0];
            int b = dimensions[i][1];

            // correct diagonal formula
            double x = sqrt(a * a + b * b);

            if(x > sq){  // found strictly larger diagonal
                sq = x;
                ans = a * b;
            }
            else if(x == sq){ // same diagonal → choose larger area
                ans = max(ans, a * b);
            }
        }

        return ans; 
    }
};
