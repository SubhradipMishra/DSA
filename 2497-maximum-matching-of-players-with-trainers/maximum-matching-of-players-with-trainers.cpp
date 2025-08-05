class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
      sort(players.begin() ,  players.end()) ; 
      sort(trainers.begin() , trainers.end()) ; 

      int n =  players.size() ; 
      int m = trainers.size() ; 

      int l =  0 ; // for players array
      int r = 0 ;  // for trainers array
      int count = 0 ; 
      while(l < n && r < m ) {
        if(players[l] <= trainers[r]){
            count++; 
            l++;

        }

        r++;  
      }


      return count ; 
    }
};