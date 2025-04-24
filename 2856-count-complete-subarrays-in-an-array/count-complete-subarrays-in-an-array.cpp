class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>s ;
        for(int i   = 0  ;i  < nums.size() ;i++){
            s.insert(nums[i]);
        }
        int total = s.size()  ;
        int count = 0 ;
        for(int i =  0 ; i <  nums.size() ; i++){
              unordered_set<int>curr ; 
          for(int j = i; j <  nums.size() ; j++){
            curr.insert(nums[j])  ;
            if(curr.size() ==  total){
                count+= (nums.size()-j)  ;
                break ;
            }
          }
        }
       return count ; 

    }
};