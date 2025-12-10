class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
         priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>> > ,
        greater<pair<int,pair<int,int >>>> pq;
        
        int n = mat.size() ; 
        int m = mat[0].size() ;
        
        vector<vector<int>> dist(n , vector<int>(m,1e9));
        dist[0][0] =  0;
        
        pq.push({0, {0,0}}) ; 
        
        
        int dr[] = {-1,0,1,0} ;
        int dc[] = {0,1,0,-1} ; 
        
        
        while(!pq.empty()){
            auto it = pq.top() ;
            pq.pop() ; 
            
            int diff = it.first ;
            int row  = it.second.first ; 
            int col  = it.second.second ; 
            
            if(row == n-1 && col == m-1)  return diff ; 
            
            
            for(int i =   0 ; i <  4 ;i++){
                int newr = row + dr[i] ;
                int newc = col + dc[i] ; 
                
                if(newr >= 0 && newc >= 0 && newr < n && newc < m ){
                   int newEffort = max(abs(mat[row][col] - mat[newr][newc]), diff);
 
                    if(newEffort < dist[newr][newc]){
                        
                    dist[newr][newc] = newEffort ; 
                    pq.push({newEffort , {newr , newc}}) ; 
                    }
                }
            }
            
            
        }
        
        
return dist[n-1][m-1];
    }
};