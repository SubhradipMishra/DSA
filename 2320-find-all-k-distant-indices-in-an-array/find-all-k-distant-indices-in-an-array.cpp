class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) { //[3,4,9,1,3,9,5]  key = 9 , k = 1 ; 
       vector<int>match ; //[2,5]
       int n  = nums.size() ;  //7 

       for(int  i = 0 ;  i   <   n ;i++ ){ // 0----->6
        if(nums[i] == key  )  match.push_back(i) ; // 2 and 5
       }  

       vector<int>ans ; 

       for(int i = 0 ; i <   n ; i++){
        for(int j =   0 ; j < match.size()  ; j++){
            if( abs(i-match[j]) <= k ) {
                ans.push_back(i) ;
                break ; 
                 }
        }
       }



       return ans ; 


    }
};