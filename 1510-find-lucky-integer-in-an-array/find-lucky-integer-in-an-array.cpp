class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n =  arr.size(); 
        unordered_map<int,int>mp;
        for(int i =  0 ; i <   n ;  i++ ) mp[arr[i]]++; 
        
        int maxLucky = -1;
        for(int   i = 0 ;  i <   n  ; i++ ){
            if(mp[arr[i]] == arr[i]) {
                maxLucky =  max(maxLucky ,arr[i])  ;
                mp[arr[i]] = 0 ; 
            }
        }


        return maxLucky  ; 
    }

};