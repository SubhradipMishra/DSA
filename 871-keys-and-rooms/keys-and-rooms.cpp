class Solution {
public:

   void bfs(vector<vector<int>>& adj ,vector<bool>&vis ){
      queue<int>q ;
      q.push(0) ; 
      vis[0] = true ; 
       while(q.size()!= 0){
        int x  = q.front() ;
        q.pop() ; 
        for(int i =  0 ; i <  adj[x].size() ; i++){
            int nextRoom = adj[x][i] ; 
            if(vis[nextRoom] == false){
                q.push(nextRoom) ;
                vis[nextRoom] = true; 
            }
        }
       }
      
         }
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n =  adj.size() ; 
        vector<bool>vis(n,false);
        bfs(adj , vis ) ;


        for(int i  = 0 ; i < n ; i++){
            if(!vis[i]) return false ; 
        }

        return true ; 
        
    }
};