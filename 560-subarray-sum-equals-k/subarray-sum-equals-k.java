class Solution {
    public int subarraySum(int[] nums, int k) {
        int n =  nums.length; 
        int count = 0 ; 
        int pre =  0 ; 
        HashMap<Integer,Integer>mp  = new HashMap<>();  
        mp.put(0 , 1);

        for(int  i =  0 ;  i < n ; i++){
            pre += nums[i] ; 
            int x = pre - k ; 
            if(mp.containsKey(x)){
                count += mp.get(x);
            }

            mp.put(pre , mp.getOrDefault(pre , 0 ) +1);
        }

        return count ; 
    }
}