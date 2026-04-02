class Solution {
public:
    void lpsFind(string needle ,  int n ,  vector<int>& lps){
        int pre = 0; 
        int suff = 1 ;
        while(suff < n){
            if(needle[pre] == needle[suff]){
                lps[suff] = pre + 1 ;
                pre++;
                suff++ ;
            }
            else{
                if(pre == 0){
                    lps[suff] = 0 ;
                    suff++;
                }
                else{
                    pre = lps[pre-1] ;
                }
            }
        }

        
    }
    int strStr(string haystack, string needle) {
        int n  = needle.size() ; 
        vector<int>lps(n , 0 ) ;
        lpsFind(needle , n  ,lps ); 
        int first = 0 ;
        int second = 0 ;

        while(first < haystack.size() && second  < needle.size()){
            if(haystack[first] == needle[second]){
                first++;
                second++;

            }
            else{
               if(second == 0 ) first++;
               else second = lps[second-1]  ; 
            }
        }

        if(second == needle.size() ) return first-second ;
        else return -1;
    }
};