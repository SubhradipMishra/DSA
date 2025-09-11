class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin() , intervals.end()) ; 
        // int n = intervals.size() ; 
        // vector<vector<int>>ans ; 
        // for(int i  =  0  ; i <  n ; i++ ){
        //      int x = ans.size()-1; 
        //      if( x <  0 ||  ans[x][1]  <  intervals[i][0])
        //      {
        //         ans.push_back(intervals[i]) ;
        //      }
        //      else{
        //         ans[x][1] = max(ans[x][1]  ,  intervals[i][1]) ;
        //      }
        // }

        // return ans ;


        sort(intervals.begin() , intervals.end());
        int n = intervals.size() ;
        vector<vector<int>>ans ; 
        for(int i = 0 ; i < n ;i++){
            int x = ans.size()-1 ;
            if(x < 0 || ans[x][1] < intervals[i][0]){
                ans.push_back(intervals[i]) ;
            }
            else ans[x][1] = max(ans[x][1] , intervals[i][1]) ;
        }

        return ans ; 
    }
};