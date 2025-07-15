class Solution {
public:
    
    bool isValid(string word) {
        if(word.size() <  3)  return false ; 
        int vo =  0 ;
        int con = 0 ;
       for(int  i  = 0 ; i < word.size() ; i++){
        if(isalpha(word[i])){
            word[i] = tolower(word[i]);
          if(word[i] == 'a' || word[i]=='e' ||  word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
           vo = 1;
           else con = 1  ;
        }
        else if(!(word[i] >= 48 && word[i] <= 57) && ! isalpha(word[i]))  return false   ;
       
       }
         if(vo == 1 && con == 1 )  return true ;
       return false ;
    }
};