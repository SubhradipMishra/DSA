class Solution {
public:
    int find(vector<int>& nums , int k ){
        if(k  < 0 ) return 0 ; 
        int n  = nums.size() ; 
        int i = 0; 
        int j =   0 ; 
        int count  = 0 ; 
        int sum =  0 ;

        while( j < n ){
          sum += nums[j] ;
          while(sum >k ){
            sum-=nums[i] ;
            i++ ;
          }    
          if(sum <= k)  count += (j-i+1);
          j++ ;
        }

        return count ; 
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i  =  0   ; i <  nums.size() ;  i++ ) {
            if(nums[i] % 2 == 0 ) nums[i]  = 0 ; 
            else nums[i] = 1  ; 
        }
        int ans=  find(nums, k) -find(nums , k-1) ;
        return ans ;
    }
};