class Solution {
public:
vector<string> findSubstrings(string s, int k) {
    int n = s.length();
    vector<string> substrings;

    if (k > n) {
     
        return substrings;
    }

    for (int i = 0; i <= n - k; i++) {
        substrings.push_back(s.substr(i, k));
    }

    return substrings;
}
 int findNoOfWhite(string s){
    int count =0  ;
    for(int i = 0 ; i < s.size() ;i++){
        if(s[i]=='W') count++ ; 
    }

    return count ;
 }

    int minimumRecolors(string blocks, int k) {
        vector<string>ans;
        ans= findSubstrings(blocks,k);
        int minCount = INT_MAX ;
        for(int  i =  0 ; i <   ans.size() ; i++){
            int x = findNoOfWhite(ans[i]) ;
            minCount = min(x,minCount) ;
        }

        return minCount ;
    }
};