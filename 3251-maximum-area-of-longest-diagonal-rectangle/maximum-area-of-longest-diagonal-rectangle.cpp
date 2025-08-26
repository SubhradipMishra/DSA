class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size(); 
        int ans = INT_MIN; 
        double sq = -1;  

        for(int i = 0; i < n; i++){
            int a = dimensions[i][0];
            int b = dimensions[i][1];

           
            double x = sqrt(a * a + b * b);

            if(x > sq){  
                sq = x;
                ans = a * b;
            }
            else if(x == sq){ 
                ans = max(ans, a * b);
            }
        }

        return ans; 
    }
};
