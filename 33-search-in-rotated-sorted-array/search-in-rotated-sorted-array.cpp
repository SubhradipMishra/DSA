class Solution {
public:
    int search(vector<int>& a, int k) {
        int n = a.size() ; 
        int lo =  0; 
        int hi = n-1;
        while(lo <= hi ) {
            int mid  = lo +  (hi-lo)/2 ; 
            if(a[mid] == k )  return mid;  
            else if(a[lo] <= a[mid]){
                if(a[lo] <= k  && k <= a[mid]) {
                    // eleement exist
                    hi  = mid - 1;

                }
                else {
                    lo = mid + 1;
                }
            }

            else{
                if(a[mid]<= k && k <= a[hi]){
                    lo  =  mid+1 ; 
                }
                else {
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};