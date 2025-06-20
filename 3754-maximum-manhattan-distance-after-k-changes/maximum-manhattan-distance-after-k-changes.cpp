class Solution{
    public:

pair<int, int> getDelta(char dir) {
    if (dir == 'N') return {0, 1};
    if (dir == 'S') return {0, -1};
    if (dir == 'E') return {1, 0};
    if (dir == 'W') return {-1, 0};
    return {0, 0};
}

int maxDistance(string s, int k) {
    int n = s.size();
    int x = 0, y = 0;
    int maxDist = 0;

    // Min heap to keep top k best gains (min-heap for popping smallest when size > k)
    priority_queue<int, vector<int>, greater<int>> bestGains;
    int totalGain = 0;

    // Store previous position
    int prevX = 0, prevY = 0;

    for (int i = 0; i < n; ++i) {
        // Apply current move
        auto [dx, dy] = getDelta(s[i]);
        x += dx;
        y += dy;

        // Original distance at this step
        int originalDist = abs(x) + abs(y);
        int bestGain = 0;

        // Try changing to each of the other 3 directions
        for (char dir : {'N', 'S', 'E', 'W'}) {
            if (dir == s[i]) continue;

            auto [ndx, ndy] = getDelta(dir);
            int newX = prevX + ndx;
            int newY = prevY + ndy;
            int newDist = abs(newX) + abs(newY);

            int gain = newDist - originalDist;
            bestGain = max(bestGain, gain);
        }

        // If this step has a positive gain, add it to heap
        if (bestGain > 0) {
            bestGains.push(bestGain);
            totalGain += bestGain;

            if ((int)bestGains.size() > k) {
                totalGain -= bestGains.top();
                bestGains.pop();
            }
        }

        // Update max distance with current position and total gain
        maxDist = max(maxDist, abs(x) + abs(y) + totalGain);

        // Save current position for next iteration
        prevX = x;
        prevY = y;
    }

    return maxDist;

}
} ; 
