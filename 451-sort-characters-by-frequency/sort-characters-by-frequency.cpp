class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp ; 
        for(int i  = 0 ; i < s.size() ; i++){
            mp[s[i]]++; 
        }

         priority_queue<pair<int,char>> pq;  
        for(auto x : mp){
            char ch = x.first ; 
            int freq = x.second ; 
            pq.push({freq,ch}) ; 
        }

       string ans = "" ;
       while(!pq.empty()){
        auto x = pq.top() ; 
        char ch = x.second ; 
        int count = x.first ; 
        ans += string(count, ch); 
        pq.pop(); 
       }

       return ans ; 
    }
};