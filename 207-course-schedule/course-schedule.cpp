class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V) ;
        vector<int>indegree(V, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ;
            indegree[it[1]]++; 
        }

       queue<int>q; 
       for(int i  =  0 ; i < V;  i++){
        if(indegree[i] == 0 ) q.push(i) ; 
       }

       vector<int>topo;

       while(!q.empty()){
        int node = q.front() ; 
        topo.push_back(node); 
        q.pop() ;
        for(auto it :adj[node]){
            indegree[it]--;
            if(indegree[it] == 0 )q.push(it) ; 
        }
       }


       return V == topo.size() ; 
    }
};