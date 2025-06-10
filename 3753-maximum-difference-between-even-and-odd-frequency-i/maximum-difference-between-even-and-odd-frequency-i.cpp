class Solution {
public:
    int maxDifference(string s) {
         unordered_map<char,int>mp ; 
         for(char ch : s ) {
            mp[ch]++ ; 
         }
         // now our task is to find the max odd frequncy and min even frequncy 

         int maxOddFrequency = INT_MIN ; 
         int minEvenFrequency = INT_MAX ; 

         for(auto x : mp ) {
            if(x.second % 2 == 0 )
               minEvenFrequency =  min(minEvenFrequency , x.second) ; 
            else
               maxOddFrequency  =  max(maxOddFrequency , x.second ) ;  
         }

         return maxOddFrequency - minEvenFrequency ; 
    }
};