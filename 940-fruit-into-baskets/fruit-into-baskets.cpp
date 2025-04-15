class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0, maxLen = 0;
        unordered_map<int, int> basket;

        while (j < fruits.size()) {
            basket[fruits[j]]++;

            while (basket.size() > 2) {
                basket[fruits[i]]--;
                if (basket[fruits[i]] == 0) {
                    basket.erase(fruits[i]);
                }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);

            j++;
        }

        return maxLen;
    }
};
