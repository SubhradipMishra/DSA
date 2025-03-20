class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n  =  arr.size() ; 
        int lsum = 0 ; 
        int rsum = 0 ; 
        int maxSum = 0  ;

        for(int i =   0 ; i <   k ; i++ ) {
            lsum+=arr[i] ; 
        }

        maxSum = lsum ; 
        int r =  n-1 ; // right index
        for(int i = k-1;i>=0 ; i--){
            lsum -= arr[i]; 
            rsum+=arr[r] ; 
            r-- ;
            maxSum = max(maxSum , lsum+ rsum ) ; 
        }

        return maxSum ; 
    }
};