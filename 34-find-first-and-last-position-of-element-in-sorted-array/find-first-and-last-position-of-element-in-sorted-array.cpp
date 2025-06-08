class Solution {
public:
    int findFirstOccurence(vector<int>& a , int k ) {
        int lo =  0 ; 
        int hi =  a.size()-1 ;
        while(lo <= hi ) {
            int mid = lo + (hi-lo)/2; 
            if(a[mid] == k ){
              if(  mid == 0 || a[mid - 1] < a[mid]   ) return mid;
              else hi = mid-1  ; 

            }
            else if(a[mid]  <   k ) lo = mid +1;
            else hi = mid- 1; 
        }

        return -1;
    }



    int findLastOccurence(vector<int>& a , int k ) {
        int lo =  0 ; 
        int hi =  a.size()-1 ;
        while(lo <= hi ) {
            int mid = lo + (hi-lo)/2; 
            if(a[mid] == k ){
              if (    mid ==  a.size()-1 || a[mid + 1]  > a[mid]   ) return mid;
              else lo = mid+ 1  ; 

            }
           else if(a[mid]  <   k ) lo = mid +1;
            else hi = mid- 1; 
        }

        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int k) {
       
       int firstOccurence = findFirstOccurence(nums,k) ; 
       int lastOccurence  = findLastOccurence(nums,k) ; 

       vector<int>ans; 
       ans.push_back(firstOccurence);
       ans.push_back(lastOccurence);

       return ans;  
       
    }
};