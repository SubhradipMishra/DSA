class Solution {
public:

     void helper(string digits , vector<string>& ans , string temp , int idx ,  vector<string>mp){
        if(idx == digits.size()){
            ans.push_back(temp) ;
            return ; 
        }
        string letters = mp[digits[idx]-'0'] ;
        for(char ch  :  letters){
            temp.push_back(ch) ; 
            helper(digits , ans , temp , idx + 1 , mp);
            temp.pop_back() ;
        }
     }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string>ans ; 

        string temp ; 

        helper(digits,ans,temp,0,mp);

        return ans ;
    }
};