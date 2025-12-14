class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        

        const int INF  = 1e9 ; 
        vector<vector<int>>dist(n , vector<int>(n,INF)) ;

        for(auto & e : edges){
            dist[e[0]][e[1]] = e[2] ; 
            dist[e[1]][e[0]] = e[2] ;
        }

        for(int i = 0 ; i < n ;i++){
            dist[i][i] = 0 ; 
        }

        for(int k  = 0 ; k < n ;k++){
            for(int i = 0 ; i < n ;i++){
                for(int j =  0 ; j < n ;j++){
                    if(dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) ; 
                    }
                }
            }
        }


        int minCount = INT_MAX ; 
        int cityNo = -1 ; 
        for(int city  = 0 ; city < n ; city++){
            int count =  0 ; 
            for(int adj =  0 ; adj < n ; adj++){
                if(dist[city][adj] <= distanceThreshold){
                    count++ ;
                }
            }

            if(count <= minCount){
                minCount = count ; 
                cityNo = city ; 
            }
        }
        
        return cityNo ;
   }
};