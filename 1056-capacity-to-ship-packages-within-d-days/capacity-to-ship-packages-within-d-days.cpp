class Solution {
public:

    bool isPossible(vector<int>& arr , int d  ,int x) {
        int dayCount = 0 ; 
        int capacity = 0  ;
        for(int i =  0  ; i <arr.size() ; i++) {
            if(capacity + arr[i] > x ){
                dayCount++ ; 
                capacity  = arr[i] ;
            } 
            else capacity += arr[i] ;
        }
        dayCount++ ; 

        return d>= dayCount ; 

    }
    int shipWithinDays(vector<int>& arr, int d) {
        int n  =  arr.size(); 
        int maxi = INT_MIN ; 
        int sum  = 0 ;
        for(int i = 0  ; i <  n ; i++ ){
            maxi = max(maxi , arr[i]) ; 
            sum += arr[i] ; 
        }

        int lo = maxi ; 
        int hi = sum ; 
        int ans = -1 ; 
        while(lo <= hi ){
            int mid = lo + (hi - lo)/2 ;
            if(isPossible(arr,d,mid)){
                ans = mid ; 
                hi = mid-1;
            }
            else lo = mid +1;

        }

        return ans; 
        
    }
};