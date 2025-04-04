class Solution {
public:
    int maxSatisfied(vector<int>& arr, vector<int>& grumpy, int k) {
      int n  =  arr.size() ; 
      int prevLoss = 0  ; 
      for(int i =   0 ; i  <  k ; i++) {
       if(grumpy[i] ==  1 )  prevLoss+= arr[i]  ;
      }
         int maxLoss =  prevLoss ; 
         int maxIdx  = 0 ; 
         int i  = 1 ; 
         int j =  k ;
         while(j  < n){
           int currLoss = prevLoss ;
           if(grumpy[j] == 1) currLoss +=  arr[j] ; 
           if(grumpy[i-1]==  1)  currLoss-=arr[i-1]  ;
           if(maxLoss <  currLoss )  {
            maxLoss = currLoss ; 
            maxIdx = i ; 
           }
           prevLoss = currLoss ; 
           i++;
           j++ ; 

         }

         for(int i  = maxIdx  ; i   <  maxIdx +   k  ; i++){
             grumpy[i] = 0 ; 
         }

         int maxS =   0 ;
         for(int  i =  0 ;  i  <  n ; i++ ) {
            if( grumpy[i] == 0 )  maxS+=arr[i] ; 
         }


         return maxS ; 


    }
};