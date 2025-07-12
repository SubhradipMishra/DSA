class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() ; 
        int k = 2 ;
        int i  = 0 ;  
        int j  = 0 ;
        int maxLen = 0  ;
        unordered_map<int,int> mp ; 
        while(j < n ){
            mp[fruits[j]]++;

            while(mp.size() > k){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0 )  mp.erase(fruits[i]) ;
                i++; 
            }

            if(mp.size()<= k ) maxLen = max(maxLen , j - i +1 ) ;
            j++ ;
         }

         return maxLen ; 

    }
};