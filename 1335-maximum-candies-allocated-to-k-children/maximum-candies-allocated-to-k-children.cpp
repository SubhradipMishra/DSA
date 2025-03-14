class Solution {
public:
    bool check(vector<int>& candies , long long k , int x){
       long long count = 0;
        for(int i =  0 ; i   < candies.size() ; i++){
            count+= candies[i]/x ;  ;
        }

     return count >= k; 
    }
    int maximumCandies(vector<int>& candies, long long k) {
 long long sum = 0;
        for(int  i  = 0 ;  i  <candies.size() ; i++){
            sum+=candies[i]; 
        }



        if(sum < k  ) return  0 ;  
        int ans = 0 ; 
           int lo = 1, hi = *max_element(candies.begin(), candies.end()); 
        while(lo <= hi){
            int mid = lo + (hi-lo)/2  ;
            if(check(candies , k,mid)){
                  ans = mid ; 
                lo = mid+1; 
              
            }

            else{
                hi = mid-1;
            }

        }

        return ans;  
    }
};