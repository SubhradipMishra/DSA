class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
         int minLen  = INT_MAX;  
         int n =  nums.size() ; 
         int i =  0  ; 
         int sum =  0  ;
         int j =  0 ;  
         while(j <  n)  {
            sum += nums[j] ; 
            while(sum >=  target){
                minLen = min(minLen , j -  i +1) ;
                sum-=nums[i]; 
                i++ ; 
            }
            
            j++ ; 
         }   
    
         return minLen == INT_MAX ? 0 :  minLen ; 
        }
    };