class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans =  0 ; 
        int n = nums.size() ; 
        long long count =  0 ; 
        vector<int>arr(n);  
        if(nums[0] == 0 ) arr[0] = 1 ; 
        else arr[0] = 0 ;
        for(int i =  1 ; i < n ; i++){
            if(nums[i] == 0 ){
                arr[i] = 1; 
                if(nums[i-1] == 0 )
                arr[i] +=arr[i-1] ;
            }
            else
            arr[i] = 0 ;  
             

        }

        for(int i =  0 ; i < n  ; i++){
            ans += arr[i] ; 
        }

        return ans ; 
    }
};