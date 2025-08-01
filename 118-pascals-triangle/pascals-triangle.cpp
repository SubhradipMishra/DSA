#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;
        
        for (int i = 0; i < numRows; i++) {
            std::vector<int> row(i + 1); // Create a vector of size i+1 for the current row
            
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row[j] = 1; // First and last element of each row is 1
                } else {
                    row[j] = result[i-1][j-1] + result[i-1][j]; // Calculate value based on the previous row
                }
            }
            
            result.push_back(row); // Push the row vector into the result vector
        }
        
        return result;
    }
};
