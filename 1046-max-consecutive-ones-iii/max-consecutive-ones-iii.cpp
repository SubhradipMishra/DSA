class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int  i = 0 ; 
      int  j = 0 ; 
      int len ;
      int maxLen =  INT_MIN ; 
      int n =  nums.size(); 
      while(j < n){
           if(nums[j]==1){
            len++ ; 
            j++ ; 

           }
           else{
            if(k>0){
                
                j++ ; 
                k-- ; 
            }
            else{
                 if(nums[i] == 0) k++ ;
                i++ ; 
            }
           }
           maxLen = max(maxLen , j-i);
      }


      return maxLen ;   
    }
};