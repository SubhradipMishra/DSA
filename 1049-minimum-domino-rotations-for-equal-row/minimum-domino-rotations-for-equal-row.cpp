class Solution {
public:
    int check(int x, const vector<int>& tops, const vector<int>& bottoms) {
        int rotationsTop = 0, rotationsBottom = 0;
        int n = tops.size();

        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return INT_MAX; // Not possible
            } else if (tops[i] != x) {
                rotationsTop++;
            } else if (bottoms[i] != x) {
                rotationsBottom++;
            }
        }
        return min(rotationsTop, rotationsBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = min(check(tops[0], tops, bottoms), check(bottoms[0], tops, bottoms));
        return (rotations == INT_MAX) ? -1 : rotations;
    }
};