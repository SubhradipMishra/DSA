class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n  = s.size() ;  //size of string
        vector<string>ans ;  // ans 
        int x =  n / k ; 
        for(int i  =  0  ; i  < n ; i+=k){
            string str = "";
            for(int  j  = i ; j < i + k && j < n  ; j++){
                str+= s[j] ; 
            }
           if(str.size() != k ){
             int ex = k - str.size() ; 
             for(int l =  0 ; l < ex ; l++){
                str += fill ; 
             }
           }
      ans.push_back(str) ;

        }
           return  ans ; 
    }
};