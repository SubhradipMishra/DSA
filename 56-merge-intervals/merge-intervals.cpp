class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; 
        vector<vector<int>> m; 
        
        // Sort intervals to ensure proper merging
        sort(intervals.begin(), intervals.end());

        int endTime = intervals[0][1]; 
        m.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > endTime) {
                // Merge all stored intervals in `m` before starting a new merge
                vector<int> newInterval(2);
                newInterval[0] = INT_MAX;
                newInterval[1] = INT_MIN;

                for (int j = 0; j < m.size(); j++) {
                    newInterval[0] = min(m[j][0], newInterval[0]);
                    newInterval[1] = max(m[j][1], newInterval[1]);
                }
                ans.push_back(newInterval);
                
                // Clear `m` and start fresh for the next set of intervals
                m.clear();
                m.push_back(intervals[i]);
            } else {
                m.push_back(intervals[i]);
            }
            endTime = max(endTime, intervals[i][1]);
        }

        // Merge the last group of intervals in `m`
        vector<int> newInterval(2);
        newInterval[0] = INT_MAX;
        newInterval[1] = INT_MIN;

        for (int j = 0; j < m.size(); j++) {
            newInterval[0] = min(m[j][0], newInterval[0]);
            newInterval[1] = max(m[j][1], newInterval[1]);
        }
        ans.push_back(newInterval);

        return ans;
    }
};
