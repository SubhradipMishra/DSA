class Solution {
public:
    const long long MOD = 1000000007LL;

    string converToBinary(int n) {
        if (n == 0) return "0";
        string ans = "";
        while (n) {
            int ld = n % 2;
            ans += to_string(ld);
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // build powers in ascending order: [2^0, 2^1, 2^2, ...] but only for bits '1'
    vector<long long> convertPowerVector(string s) {
        vector<long long> ans;
        int len = (int)s.size();
        // iterate from LSB to MSB so indices match queries (0 -> 2^0, 1 -> 2^1, ...)
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] == '1') {
                int exp = (len - 1 - i); // exponent for this bit
                ans.push_back(pow_mod(2, exp)); // already modded
            }
        }
        return ans;
    }

    void findPreArray(vector<long long>& pre, int n, const vector<long long>& powers) {
        for (int i = 1; i < n; ++i) {
            pre[i] = (pre[i - 1] * powers[i]) % MOD; // compute prefix product modulo MOD
        }
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        string binary = converToBinary(n);
        vector<long long> powers = convertPowerVector(binary);

        if (powers.empty()) return vector<int>(queries.size(), 0);

        vector<long long> pre(powers.size());
        pre[0] = powers[0] % MOD;
        findPreArray(pre, (int)powers.size(), powers);

        vector<int> ans;
        ans.reserve(queries.size());
        for (int i = 0; i < (int)queries.size(); ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            long long x;
            if (l == 0) {
                x = pre[r];
            } else {
                // modular division: pre[r] * inv(pre[l-1]) % MOD
                long long inv = pow_mod(pre[l - 1], MOD - 2);
                x = (pre[r] * inv) % MOD;
            }
            ans.push_back((int)(x % MOD));
        }
        return ans;
    }

private:
    // fast exponentiation modulo MOD
    long long pow_mod(long long base, long long exp) {
        base %= MOD;
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
};
