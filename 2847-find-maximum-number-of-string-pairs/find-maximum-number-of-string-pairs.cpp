class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
     int count = 0 ; 
     unordered_set<string>st ;  
     for(int i = 0 ; i  < arr.size() ; i++){
        string s = arr[i] ; 
        reverse(s.begin() , s.end()) ;
        if(st.find(s) != st.end()) count++;
        else {
            st.insert(arr[i]) ; 
        }
     }  
     return count ;  
    }
};