class Solution {
public:  
void reverse(string& str) {
        int l = str.length();
        int i = 0;
        int j = l - 1;
        while (i < j) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }
     
    string reverseWords(string s) {
        reverse(s);
        string word = "";
        string res ="";
        int n = s.size() ;
        for(int i =  0 ; i < n ;i++){
            if(s[i] == ' '){
                if(word.size()!=0){
                    reverse(word);
                    res  = res + word + " ";
                    word = "";
                }
            }
                else {
                    word += s[i] ; 
                }
            
        }

                reverse(word);
        res += word;

        if(!res.empty() && res.back()==' ')
         res.erase(res.size() - 1);




       return res; 



    }
};