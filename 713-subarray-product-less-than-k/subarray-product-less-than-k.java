class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
         int n =  nums.length ; 
         int count =  0 ; 
         int  i =  0 ; 
         int  j =  0  ;
         int prod = 1 ; 
         while( j  < n  ){
            prod*= nums[j];
            while(prod  >= k && i <= j ){
                prod /= nums[i] ;
                i++ ; 

            }
            count += j - i +1;
            j++ ; 
         }

         return count ; 
    }
}