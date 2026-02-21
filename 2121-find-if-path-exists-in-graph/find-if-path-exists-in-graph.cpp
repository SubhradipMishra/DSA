class Solution {
public:

    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int s){
        visited[s] = true;

        for(auto x : adjList[s]){
            if(!visited[x])
                dfs(adjList, visited, x);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        
       
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(adjList, visited, src);

        return visited[dest];
    }
};