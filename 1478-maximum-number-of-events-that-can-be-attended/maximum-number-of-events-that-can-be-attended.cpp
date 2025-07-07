class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); // sort by start day
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0, n = events.size();
        int res = 0;

        int day = 1;
        while (!pq.empty() || i < n) {
            // push events starting today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            // remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            if (!pq.empty()) {
                pq.pop();  // attend the earliest-ending available event
                res++;
            }

            day++;
        }
        return res;
    }
};
