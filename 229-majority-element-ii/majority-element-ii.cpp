class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int el1,el2 ; 
        int count1 = 0 ; 
        int count2 = 0 ; 

        for(int i  = 0 ; i  < n  ;i++){
            if(count1 == 0 && el2 != nums[i]){
                count1 = 1 ; 
                el1= nums[i] ;
            }
           else if(count2 == 0 && el1 != nums[i]){
                 count2 = 1 ; 
                el2= nums[i] ;
            }

            else if( el1 == nums[i] ){
                count1++ ;
            } 

             else if( el2 == nums[i] ){
                count2++ ;
            } 

            else{
                count1--;
                count2--;
            }

        }

        count1 = 0 ; 
        count2 = 0 ; 
        for(int i  = 0 ; i < n ; i++){
            if(el1 == nums[i]) count1++ ;
            else if(el2 ==  nums[i] ) count2++ ; 

        }

            int mini = n / 3 + 1;
            vector<int> ls;
            if (count1 >= mini) ls.push_back(el1);
            if (count2 >= mini) ls.push_back(el2);


            return ls  ; 



    }
};