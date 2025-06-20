class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpS , mpT; 
        if(s.size() != t.size() )  return false ; 
        for(char ch : s){
            mpS[ch]++ ; 
        }

        for(char ch : t) {
            mpT[ch]++ ; 
        }

        for(auto x : mpS ){
            if(mpT.find(x.first) != mpT.end()){
                if(mpS[x.first] != mpT[x.first]) return false;
            }
            else return false ;
        }

        return true ; 

    }
};