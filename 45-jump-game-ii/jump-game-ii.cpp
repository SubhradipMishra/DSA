class Solution {
public:
    int jump(vector<int>& nums) {
        int n =  nums.size() ; 
        int jump = 0 ;
        int end=0;
        int maxi = 0 ; 
        for(int i =  0 ; i  <n-1 ; i++){
              maxi  = max(maxi ,nums[i] + i  ) ;

              if(i == end){
                jump++ ;
                end = maxi ; 
              }
        }


        return jump; 

    }
};