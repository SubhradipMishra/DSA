class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int count = 0;  
        int jump = 0;  

        for (int i = 0; i < n; ) {
            if (i + nums[i] >= n - 1) {
                count++;
                break;
            }

            int x = i + nums[i]; 
            int maxE = INT_MIN;
            int nextPos = i;

            for (int j = i + 1; j <= x && j < n; j++) {
                if (j + nums[j] > maxE) {
                    maxE = j + nums[j];
                    nextPos = j;
                }
            }

            i = nextPos;
            count++;  
        }

        return count; 
    }
};
