class Solution {
public:
    bool check(vector<int>& nums , int mid , int t){
        int count = 0; 
        for(int i  = 0;  i < nums.size() ; i++){
            if(count >  t )  return false ;
            if(nums[i] <=  mid )  count+=1 ; 
            else{
                if(nums[i] % mid == 0 ) count += nums[i]/mid ; 
                else count+= ((nums[i]/mid) + 1) ; 
            }

            
        }

        return count <= t ; 
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size() ; 
        int lo = 1; 
        int maxi = INT_MIN ; 
        for(int i =  0;  i <  n ; i++){
            maxi= max(nums[i] , maxi) ; 
        }

        int hi = maxi; 
        int ans = -1 ; 


        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            if(check(nums,mid,t)){
                ans = mid; 
                hi= mid-1 ;
            }
            else {
                lo = mid+1;
            }
        }



        return ans ; 

    }
};