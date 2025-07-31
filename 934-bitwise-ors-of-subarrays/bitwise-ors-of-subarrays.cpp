class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;

        for (int num : arr) {
            unordered_set<int> curr;
            curr.insert(num);
            for (int val : prev) {
                curr.insert(val | num);
            }
            result.insert(curr.begin(), curr.end());
            prev = curr;
        }

        return result.size();
    }
};
