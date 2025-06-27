class Solution {
public:
   void dfs(int st , vector<int>adj[] , vector<int>& vis){
    vis[st] = 1 ; 
    for(auto it : adj[st]){
        if(vis[it] == 0 ){
            dfs(it, adj ,vis) ; 
        }
    }
   }
    int findCircleNum(vector<vector<int>>& adj) {
        int v = adj.size() ; 
        vector<int>adjList[v] ; 

        // convert adj matix to adj list

        for(int i  =  0 ; i < v ; i++){
            for(int j = 0 ; j < v ; j++ ){
                if(adj[i][j] == 1 && i!= j){
                    adjList[i].push_back(j) ; 
                      adjList[j].push_back(i) ; 
                }
            }
        }
           
           // create visited array
            vector<int>vis(v,0) ; 
            
          // no of provinces
           int count = 0 ; 

          // check which node are not visited amd run dfs for only this node

            for(int i  =   0 ; i  < v  ; i++){
                if(!vis[i]){
                    count++;  
                    dfs(i , adjList , vis) ; 
                }
            }

            
          
        return count ; 
    }
};