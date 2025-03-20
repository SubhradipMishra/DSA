class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int n = arr.size();
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int count = 0;
        int i = 0, j = k;

        if (sum / k >= t) {
            count++;
        }

        while (j < n) {
            sum = sum - arr[i] + arr[j];
            if (sum / k >= t) {
                count++;
            }
            i++;
            j++;
        }

        return count;
    }
};
