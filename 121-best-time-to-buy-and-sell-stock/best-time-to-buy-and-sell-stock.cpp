class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        int minBuy = prices[0];
        int maxProfit = 0 ; 
        for(int i =  1 ; i <  n ; i++)
        {
            if(minBuy >   prices[i])  minBuy  = prices[i] ; 
            else{
                maxProfit = max(maxProfit , prices[i] - minBuy) ; 
            }
        }

        return maxProfit ;
    }
};