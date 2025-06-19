class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
     int n = nums.size() ; 
     sort(nums.begin() , nums.end())  ;
     int count = 0 ; 
     int i  =  0 ; 
     while( i  < n ) {
        int s = nums[i] ; 
        while(i < n && nums[i] - s <=  k ){
            i++ ; 
        }
        count++ ;
     }   

     return count ; 
    }
};