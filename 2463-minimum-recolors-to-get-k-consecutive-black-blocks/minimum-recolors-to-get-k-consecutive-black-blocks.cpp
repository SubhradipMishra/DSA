class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        vector<int>ans;
        for(int i = 0 ; i <= blocks.size() - k ; i++){
            string str = blocks.substr(i,k);
            int x = count(str.begin(),str.end(),'W');
            ans.push_back(x);            
        }
        return *min_element(ans.begin(),ans.end());
        
    }
};