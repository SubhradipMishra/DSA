class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //     int n = nums.size()-1;
    //     int x = n*(n+1)/2;
    //     int sum  = 0 ; 
    //     for(int  i =   0 ; i <  nums.size() ;i++){
    //         sum+= nums[i] ;
    //     }
    //     return sum-x;
    // }

    unordered_map<int,int>mp;
    int n  = nums.size() ;
    for(int i = 0 ;i < n;i++){
          mp[nums[i]]++;
    }

    for(int i  = 0 ; i < n ;i++){
        if(mp[nums[i]]!=1) return nums[i] ;
    }
    return  0 ;
    }
};