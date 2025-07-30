class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len =  1 ; 
        int mx =  *max_element(nums.begin() , nums.end());
        int tempLen = 0 ;
        for(int i =  0  ; i <  nums.size() ;i++){
            if(mx == nums[i]){
                tempLen++;
            }
            else {
                len = max(len ,tempLen );
                tempLen = 0 ;
            }
        }


      len = max(len, tempLen);
        return len ; 

    }
};