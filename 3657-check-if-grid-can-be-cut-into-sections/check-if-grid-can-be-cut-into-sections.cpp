class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return helper(rectangles, 0) || helper(rectangles, 1);
    }
private:
    bool helper(vector<vector<int>>& rectangles, int cor){
        int cuts = 0;
        sort(rectangles.begin(), rectangles.end(), [cor]
            (const vector<int>& a, const vector<int>& b){
                return a[cor] < b[cor];
            }
        );
        int end = rectangles[0][cor + 2];
        for(int i = 1; i < rectangles.size(); i++){
            if(end <= rectangles[i][cor])
                cuts++;
            end = max(end, rectangles[i][cor + 2]);
        }
        if(cuts >= 2)   return true;
        return false;
    }
};
