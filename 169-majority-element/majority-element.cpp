class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n =  nums.size() ; 
        // int el ;
        // int count = 0 ; 
        // for(int  i =  0  ; i < n  ;i++){
        //     if(count == 0 ){
        //         count = 1 ; 
        //         el = nums[i] ;
        //     }
        //     else if(el == nums[i]){
        //         count++;
        //     }
        //     else count--;
        // }

        // return el ; 

        int n = nums.size() ; 
        int el ; 
        int count = 0;
        for(int i  = 0 ; i  < n ; i++){
            if(count == 0 ){
                count = 1 ; 
                el = nums[i] ; 
            }
            else if(el == nums[i]){
                count++;
            }
            else count--;


        }
    
    return el ; 
    }
};