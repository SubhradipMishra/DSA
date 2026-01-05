class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int n = tasks.size();

        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        long long timer = 0;
        int i = 0;

        while (i < n || !pq.empty()) {

            if (pq.empty() && timer < tasks[i][0]) {
                timer = tasks[i][0];
            }

            while (i < n && tasks[i][0] <= timer) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            auto x = pq.top();
            pq.pop();

            timer += x.first;
            ans.push_back(x.second);
        }

        return ans;
    }
};
