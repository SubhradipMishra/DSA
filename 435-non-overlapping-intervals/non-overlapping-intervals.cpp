bool comp( vector<int> a , vector<int>b){
    return a[1]  < b[1] ; 
}
class Solution {

public:


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ; 
        sort(intervals.begin() ,intervals.end() ,comp);

        int endTime =  intervals[0][1] ;
        int count = 1 ; 
        for(int i = 1;  i < n ; i++){
            if(endTime <= intervals[i][0]){
                count++; 
                endTime = intervals[i][1];
            }
        }

        return  n - count ;
    }
};