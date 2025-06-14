class Solution {
public:
    int minMaxDifference(int num) {
       string str = to_string(num);
       string ma = "" ;
       string mi ="" ;
       int n = str.size() ; 
       char ele = ' ';
       // find first non-9 digit for max replacements

       for(int i  =  0 ; i < n ;i++){
        if(str[i] != '9'){
            ele  = str[i] ;
            break ; 
        }
       }

       //  Replace that digit with 9 for max
        for(int i=0;i<n;i++){
            if(ele == str[i]) ma += '9';
            else ma += str[i];
        }

        //  Replace first digit for min with 0
        for(int i=0;i<n;i++){
            if(str[0] == str[i]) mi += '0';
            else mi += str[i];
        }


         return stoi(ma) - stoi(mi);

    }
};