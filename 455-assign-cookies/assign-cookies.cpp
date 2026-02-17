class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin() , g.end()) ; 
      sort(s.begin()  , s.end()) ; 

      int n = g.size() ; 
      int m = s.size(); 
      int i =  0 ; // for greed array 
      int j = 0 ; // for cookie size 
      int count = 0 ;


      while(i < n && j  < m ){
        if( g[i] <= s[j] ) {
            count++;
            i++ ;
        }
        j++;
      }


     return count ; 

    }
};