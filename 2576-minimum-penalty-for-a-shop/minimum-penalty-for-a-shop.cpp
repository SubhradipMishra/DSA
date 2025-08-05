class Solution {
public:
    int bestClosingTime(string customers) {
      int n = customers.size() ; 
      vector<int>pre(n+1 ,  0 ) ; 
      vector<int>suf(n+1,  0  ) ;

      int p = 0 ;  
      for(int  i =   1  ; i <=  n  ; i++){
        if(customers[i-1] == 'N') p++ ; 
        pre[i] = p  ; 
      }

      p =  0 ; 
    
    for(int i =  n-1 ; i>= 0 ; i--){
      if(customers[i] ==  'Y') p++ ; 
      suf[i] =  p ; 
    } 

    int minPenalty = suf[0] + pre[0] ; 
    int minIdx = 0;

    for(int i  = 1 ; i <=  n ; i++){
        int currPenalty = pre[i] +  suf[i]; 
        if(currPenalty < minPenalty){
            minPenalty = currPenalty ; 
            minIdx = i ;  
        }
    }

    return minIdx;
 
    }
};