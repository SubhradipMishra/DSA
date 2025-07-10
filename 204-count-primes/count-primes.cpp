class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        int primeCount = 0;
        for (int i = 2; i < n; i++) { // Use i < n to count primes strictly less than n
            if (isPrime[i]) {
                primeCount++;
            }
        }

        return primeCount;
    }
};
