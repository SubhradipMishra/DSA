class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      int len = tasks.size() ; 
      unordered_map<char,int>mp ; 
      for(int i =   0 ;  i < len  ; i++){
        mp[tasks[i]]++ ; 
      
      }


     // find maximum frequency character

     int maxFreq = INT_MIN ;  
     for(auto x : mp){
        int freq =  x.second ; 
        maxFreq  = max(maxFreq , freq) ; 

     }


     int ans = (maxFreq - 1) * (n+1)  ; 
     
       for(auto x : mp){
        int freq =  x.second ; 
        if(freq == maxFreq) ans++ ; 

     }


      ans =  max(len , ans) ; 
      return ans ; 

    }
};