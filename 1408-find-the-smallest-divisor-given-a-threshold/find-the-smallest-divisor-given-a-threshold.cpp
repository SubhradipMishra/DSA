class Solution {
public:
    bool check(vector<int>& nums , int t , int x) {
        int sum =  0 ; 
        for(int i  = 0 ; i <  nums.size() ; i++ ) {
            if(sum >  t )  return false ; 
            if(nums[i] % x == 0 )  sum +=  nums[i]/x; 
            else sum+= nums[i]/x +1 ;
        }

        return t >= sum ; 
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int n  =  nums.size() ; 
       
        int maxi = INT_MIN ;
        for(int i  = 0 ; i < n   ; i++ ) {
            maxi  =  max(nums[i] , maxi) ; 


        }

        int lo = 1 ; 
        int hi =  maxi;  
        int ans = -1;

        while(lo <= hi ) {
            int mid = lo + (hi - lo)/2 ;
            if(check(nums ,t, mid ))  {
                ans = mid ; 
                hi = mid - 1;
            }
            else lo = mid+1;
        }

        return ans; 
    }
};