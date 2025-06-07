class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        map<int,int>mp ; 
        int n = nums.size() ; 
        for(int  i = 0 ; i < n  ; i++ ) {
            mp[nums[i]] = i ; 

        }
        vector<int>v ; 

        for(int i =  0 ;  i <  n ;i++){
            if(mp.find(k - nums[i]) != mp.end() && i != mp[k-nums[i]]) {
                v.push_back(i) ;
                v.push_back(mp[k-nums[i]]) ; 
                mp.erase(nums[i]) ; 
            }


        }

        return v ;
    }
};