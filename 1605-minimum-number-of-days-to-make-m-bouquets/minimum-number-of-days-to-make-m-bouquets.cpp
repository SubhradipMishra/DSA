class Solution {
public:
    bool isPossible(vector<int>& arr , int d , int  m , int k){
        int n =  arr.size() ; 
        int count = 0;
        int noOfB = 0 ; 
        for(int i  = 0  ; i < n ; i++ ) {
            if(arr[i] <= d) {count++;
            if(count == k ) {
                noOfB++ ; 
                count = 0 ; 
                
            }
        }
            else count = 0 ; 
        }       

        return noOfB >= m ; 
     }
    int minDays(vector<int>& arr, int m, int k) {
        
        int n = arr.size() ;
        long long totalFlower  = (long long)m*k ; 
        if(n < totalFlower )  return -1;
       int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        int lo = mini ; 
        int hi = maxi ; 
        int ans = -1;
         while( lo <= hi ) {
            int mid = lo + (hi - lo )/2;
            if(isPossible(arr,mid,m,k)) {
                ans = mid ; 
                hi = mid-1;
            }         
            else lo = mid + 1 ; 
        }

        return ans ; 
    }
};