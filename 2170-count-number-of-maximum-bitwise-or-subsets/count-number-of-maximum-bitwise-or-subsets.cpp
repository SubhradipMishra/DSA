class Solution {
public:
    void helper(vector<int>& nums,int i ,int sum ,int& count ,int k ){
        if(i == nums.size()){
            if(sum == k)count++;
            return ; 
        }
        helper(nums,i+1,sum,count,k);
        helper(nums,i+1, sum | nums[i] ,count, k) ;
    }
    int countMaxOrSubsets(vector<int>& nums) {
       int n = nums.size() ; 
       int orAns = 0  ;
       for(int i = 0 ; i< n ;i++){
         orAns = orAns |  nums[i];
       }
       int count = 0 ; 
       helper(nums,0,0,count,orAns);

       return count ; 

    }
};