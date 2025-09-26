class Solution {
    public int subarraysDivByK(int[] nums, int k) {
      HashMap<Integer,Integer>mp =  new HashMap<>() ;
      int count = 0 ;
      int pre = 0 ;
       mp.put(0, 1);
      int n = nums.length ; 
       for(int i =   0 ; i <  n ; i++){
          pre += nums[i] ; 

           int x = ((pre % k) + k) % k;

          if(mp.containsKey(x )){
            count += mp.get(x) ;
          }
             mp.put(x, mp.getOrDefault(x, 0) + 1);

       }

       return count ; 
    }
}