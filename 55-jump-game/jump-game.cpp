class Solution {
public:
    bool canJump(vector<int>& nums) {
     int maxIdx = 0 ; 
     int n = nums.size() ;
     for(int  i  = 0 ; i < n ; i++){
        if( i >  maxIdx ) return false ; 
       int x =   i + nums[i] ;
        maxIdx = max(maxIdx , x) ; 
     }   

     return maxIdx >= n-1; 
    }
};