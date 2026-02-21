class Solution {
public:

    bool bfs(vector<vector<int>>& adj , vector<int>& color , int st){
        queue<int>q ; 
        q.push(st);
        while(!q.empty()){
            int node = q.front() ; 
            q.pop() ; 
            for(auto it : adj[node]){
                if(color[it] == -1 ){
                    q.push(it);
                    color[it] = !color[node] ; 
                }
                else if(color[it]  == color[node]) return false ; 
            }
        }

        return true ; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size() ; 
        vector<int>color(v,-1);
        for(int i =  0  ; i <  v ; i++){
            if(color[i] ==-1) 
            if(!bfs(graph ,color , i)) return false ;  
        }


        return true ; 
    }
};