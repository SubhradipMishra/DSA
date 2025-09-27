class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length ; 
        if(n <  2) return  false ; 
        HashMap<Integer,Integer>mp = new HashMap<>() ; 
        mp.put(0 , -1 );
        int prefixSum = 0 ; 
        for(int  i =  0 ; i < n ; i++){
          prefixSum += nums[i] ;
          int x = prefixSum %k ;
          if(mp.containsKey(x) ){
            int sidx = mp.get(x);
             
                if(i - sidx >= 2) return true;

          }
          else{
            mp.put(x,i);
          }
       
    }


    return false  ; 
    }
}