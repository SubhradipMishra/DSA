class Solution {
public:
    int maxArea(vector<int>& height) {
     int n =  height.size() ; 
     int i = 0 ; 
     int j =  n-1;
     int maxi = INT_MIN  ; 
     while(i < j){
         int minH = min(height[i]  , height[j]) ; 
         int x = j -i ; 
         int area = minH*x ;
         maxi = max(maxi , area) ;
         if(height[i] < height[j]) i++;
         else j--;
     }

     return maxi  ;

    }
};