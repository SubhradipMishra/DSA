class Solution {
public:
    int searchInsert(vector<int>& a, int x) {
        int n = a.size()  ;
	int lo =  0 ;  
	int hi = n - 1;
	if(a[n-1] < x ) return n ; 
	int ans = -1  ; 
	while(lo<=hi){
		int mid = lo + (hi-lo)/2   ;  
		if(a[mid] >=x ) {
			ans = mid; 
			hi = mid - 1;

		}

		else lo = mid+1; 
	}

	return ans; 
    }
};