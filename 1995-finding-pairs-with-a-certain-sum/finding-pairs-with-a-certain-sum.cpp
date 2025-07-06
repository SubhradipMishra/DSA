class FindSumPairs {

    private:
    unordered_map<int,int>mp ; 
    vector<int>n1,n2 ;
public:
   
   
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1  =  nums1 ;
        n2  = nums2 ; 
        for(int x :  n2) {
            mp[x]++ ;
        }
    }
    
    void add(int index, int val) {
        mp[n2[index]]-- ; 
        n2[index]+= val  ;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0 ; 
        for(int x :  n1) {
            ans += mp[tot - x] ; 
        }

        return ans ; 
    }
};

