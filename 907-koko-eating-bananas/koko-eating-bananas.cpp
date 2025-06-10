class Solution {
public:
    bool check(vector<int>& piles,int h , int x ){
        int count = 0 ;
        int n =  piles.size() ; 
         for(int i  = 0  ;  i <  n; i++ ) {
              if(count > h ) return false; 
            if(piles[i] % x ==  0 ) count+= piles[i] /x; 
            else count+=(piles[i] /x) +1 ;


         }

         return count <= h;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size() ; 
        int lo = 1 ; 
        int maxi = -1;
        for(int  i =  0; i <  n  ; i++  ){
            if(maxi  <  piles[i] ) maxi = piles[i] ; 

        }
        int hi = maxi ; 
        int ans = -1;
        while(lo <= hi ){
            int mid = lo + (hi-lo)/2;
            if(check(piles,h,mid)){
                ans = mid ; 
                hi = mid-1;
            }
            else lo = mid+1; 
        }

        return ans ; 
    }
};