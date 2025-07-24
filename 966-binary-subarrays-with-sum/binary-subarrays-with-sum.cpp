class Solution {
public:
    int find(vector<int>& nums,  int goal){
         if(goal <0 ) return 0;
        int  n = nums.size() ; 
        int i =  0  ;
        int j  = 0 ; 
        int count = 0 ; 
        int sum = 0  ;
        while( j < n  ){
            sum += nums[j] ; 
            while(sum> goal) {
                sum -= nums[i] ; 
                i++ ;
            }

            count += (j-i+1);
            j++ ; 
        }

        return count; 
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
          int ans =    find(nums , goal) - find(nums,goal-1);
          return ans ; 
    }
};