class Solution {
public:
    int maxSum(vector<int>& nums) {
     set<int>st ; 
     int n =  nums.size(); 
     int ans = 0 ; 
     sort(nums.begin() , nums.end()) ; 
     int fi = -1 ;
     for(int  i   =  0 ; i <  n ; i++){
      if(nums[i] >= 0 ) {
        st.insert(nums[i]) ; 
    
      }
     }

     if(st.size() == 0 )  return nums[n-1] ; 
     for(auto x : st){
      ans+= x ; 
     }

     return ans ; 
    }
};