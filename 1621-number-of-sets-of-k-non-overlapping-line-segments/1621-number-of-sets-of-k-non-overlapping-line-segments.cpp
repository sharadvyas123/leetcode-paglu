class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        long long total_items = n + k - 1;
        long long r = 2 * k;

        if ( r > total_items)return 0;

        if (r > total_items - r) {
            r = total_items - r;
        }

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 1; i <= r; ++i) {
            numerator = (numerator * (total_items - i + 1)) % MOD;
            denominator = (denominator * i) % MOD;
        }

        return (numerator * power(denominator, MOD - 2, MOD)) % MOD;
    }
private:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};