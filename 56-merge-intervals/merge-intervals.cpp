class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
       int n = arr.size();

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
         int x = ans.size()  -1;
        if (ans.empty() || arr[i][0] > ans[x][1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans[x][1] = max(ans[x][1], arr[i][1]);
        }
    }
    return ans;
    }
};
