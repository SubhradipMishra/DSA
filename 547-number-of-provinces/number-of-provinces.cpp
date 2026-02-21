class Solution {
public:

      void dfs(vector<vector<int>>& adj , vector<bool>& visited , int st){
        visited[st] = true ; 
        for(auto x :  adj[st]) {
            if(!visited[x])
            dfs(adj  ,  visited , x) ; 
        }
      }
    int findCircleNum(vector<vector<int>>& adj) {
        int v =  adj.size() ; 
        vector<vector<int>>adjList(v) ;
        for(int i =  0  ; i  < v ;  i++  ){
            for(int j =  0 ; j < v ; j++){
                if(adj[i][j] == 1 && i!=j){
                    adjList[i].push_back(j) ; 
                    adjList[j].push_back(i) ; 
                }
            }
        } 

        vector<bool>visited(v,false) ;
        int count = 0 ;

        for(int i = 0 ; i <  v ; i++){
            if(!visited[i]){
                count++;
                dfs(adjList , visited , i) ;
            }
        }

        return count ; 

    }
};