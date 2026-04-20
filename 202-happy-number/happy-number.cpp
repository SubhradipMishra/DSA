class Solution {
public:
    int solve(int n){
        int ans = 0 ;
        while(n!=0){
            int ld  = n%10 ; 
            ans += ld*ld ; 
            n/=10 ;
        }

        return ans; 
    }
    bool isHappy(int n) {
        unordered_set<int>st ;
        while(n!=1){
           n = solve(n);
           if(st.find(n) != st.end())  return false ; 
           st.insert(n) ; 


        }

        return true; 
    }
};