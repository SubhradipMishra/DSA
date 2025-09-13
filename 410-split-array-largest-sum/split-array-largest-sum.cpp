class Solution {
public:
    bool isPossible(vector<int>& arr , int mid , int k){
        int n = arr.size() ;  
        int total =  0 ;
        int count = 1; 
        for(int i = 0  ; i  <  n ; i++){
            if(arr[i]  > mid ) return false; 
            if(arr[i] + total >  mid){
                count++;
                total =  arr[i] ;
            }
            else 
              total += arr[i];
        }


        return count <= k ; 
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() ; 
        if( k > n ) return -1  ; 

         int maxi = INT_MIN ; 
         int sum  = 0 ;
         int  ans =1;
         for(int i  =  0; i  < n ; i++){
            sum +=nums[i] ;
            maxi = max(maxi  ,nums[i]) ; 
         }
         int lo = maxi  ;
         int hi = sum ; 

         while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(isPossible(nums, mid , k)){
                ans = mid ; 
                hi = mid-1;
            }
            else lo = mid+1;
         }

         return ans ; 
    }
};