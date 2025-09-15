class Solution {
public:
    bool check(string word ,set<char>& st){
        for(char ch : word){
            if(st.find(ch) != st.end()) return false; 
        }

        return true ;
    }
    int canBeTypedWords(string text, string broken) {
        
        string word = "";
        int n  = text.size();
        int count  = 0 ; 
        set<char>st ; 
        for(char ch : broken){
            st.insert(ch) ;
        }
        for(int i =  0 ; i < n ; i++){
            if(text[i] != ' ')
             word+=text[i];
             else{
                if(check(word,st)) count++;
                word="";
             }
        }

        if(check(word,st)) count++;

        return count ;
    }
};