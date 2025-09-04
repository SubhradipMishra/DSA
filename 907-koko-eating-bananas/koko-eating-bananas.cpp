class Solution {
public:
   bool check(vector<int>& piles,int mid , int h){
    int n = piles.size(); 
    int count = 0 ; 
    for(int i =  0 ; i < n ; i++ ){
         if(count > h )  return false ;
         if(piles[i] <= mid) count++; 
         else{
            if(piles[i] % mid == 0 ) count+= piles[i]/mid ;
            else count+= (piles[i]/mid) + 1; 
    }
   
    } 
     return count <= h ; 
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n =  piles.size() ;
        int maxi = INT_MIN ;
        for(int i  = 0 ; i < n  ;i++){
            maxi = max(maxi , piles[i]) ;
        }

        int lo = 1 ;
        int hi = maxi ; 

        int ans = -1 ; 

        while(lo <= hi ){
            int mid = lo +(hi-lo)/2 ;
            if(check(piles,mid,h))
            {
                ans = mid ; 
                hi = mid - 1  ;
            }
            else lo = mid + 1 ;
        }

        return ans ;
    }
};