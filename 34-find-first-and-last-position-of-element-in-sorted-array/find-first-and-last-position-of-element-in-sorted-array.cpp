class Solution {
public:
     int firstOccurence (vector<int>arr , int k){
        int lo = 0 ;
        int hi = arr.size()-1 ; 
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            if(arr[mid] == k ){
                if(mid == 0 || arr[mid] != arr[mid-1] ) return mid; 
                else hi = mid-1;
            }
            else if(arr[mid] < k ) lo = mid+1;
            else hi = mid-1; 
        }

        return -1;
     }

      int lastOccurence (vector<int>arr , int k){
        int lo = 0 ;
        int hi = arr.size()-1 ; 
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            if(arr[mid] == k ){
                if(mid == arr.size()-1 || arr[mid] != arr[mid+1] ) return mid; 
                else lo = mid+1;
            }
            else if(arr[mid] < k ) lo = mid+1;
            else hi = mid-1; 
        }

        return -1;
     }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans(2,-1); 
        int f = firstOccurence(nums,target);
        if(f == -1) return ans ; 
        int l = lastOccurence(nums,target);
        ans[0] = f;
        ans[1] = l;

        return ans ; 
    }
};