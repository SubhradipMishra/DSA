bool comp(vector<int>a , vector<int> b){
    return a[1]  <  b[1]  ;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int count = 0 ; 
        sort(inter.begin() , inter.end() , comp) ;

        int end = inter[0][1] ; 
        for(int  i =  1 ; i   < inter.size() ; i++)
        {
            if(end <= inter[i][0]){
                end = inter[i][1] ; 
            }

            else {
                count++; 
            }
        }

        return count ;
    }
};