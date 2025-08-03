class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int n = fruits.length;
        int maxFruit = 0;
        int currSum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currSum += fruits[right][1];

            while (left <= right) {
                int leftPos = fruits[left][0];
                int rightPos = fruits[right][0];

                int goLeftThenRight = Math.abs(startPos - leftPos) + (rightPos - leftPos);
                int goRightThenLeft = Math.abs(startPos - rightPos) + (rightPos - leftPos);

                if (Math.min(goLeftThenRight, goRightThenLeft) <= k) {
                    break;
                }

                currSum -= fruits[left][1];
                left++;
            }

            maxFruit = Math.max(maxFruit, currSum);
        }

        return maxFruit;
    }
}
