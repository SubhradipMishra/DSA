class Solution {
public:
static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int  res  = 0 ; 
        sort(intervals.begin() , intervals.end(),compare); 
        int  endTime = intervals[0][1] ; 
        for(int i  =  1 ; i  <intervals.size() ; i++  ){
            if(intervals[i][0] < endTime ) res++ ; 
           else endTime =  intervals[i][1]; 
        }

        return res ; 
    }
};