class Solution {
public:
    int helper(vector<int>& nums , int st , int end , vector<int>& dp){
        if(st >  end )  return  0; 
        if(dp[st]!=-1) return dp[st] ; 

        int  rob =  nums[st]  + helper(nums , st + 2  , end , dp) ; 
        int  skip =  helper(nums , st + 1  , end , dp)  ; \

        return dp[st]  = max(rob , skip) ; 

        
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ; 
        if( n == 1) return nums[0] ;
        
        // exclude first element
 

           vector<int>dp1(n,-1) ;
           int r1 =  helper(nums , 1 , n -1 , dp1 ) ; 

           vector<int> dp2(n, -1);
           int r2 = helper(nums, 0, n - 2, dp2);
           


           return max(r1 ,r2) ; 

           
          

 

    
    }
};