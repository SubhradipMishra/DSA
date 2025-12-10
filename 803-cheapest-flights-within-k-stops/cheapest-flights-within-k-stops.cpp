class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // queue => (stops, node, cost)
        queue< tuple<int,int,int> > q;

        q.push({0, src, 0});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto item : adj[node]) {
                int adjNode = item.first;
                int edW = item.second;

                if (cost + edW < dist[adjNode]) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, adjNode, cost + edW});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
