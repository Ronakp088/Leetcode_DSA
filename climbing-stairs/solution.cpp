class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n - r) r = n - r;
        long long result = 1;
        for (int i = 0; i < r; i++) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        long long ans = 0;
        int i = 0;
        while ((2*i) <= n) {
            ans += nCr(n - i, i);
            i++;
        }
        return ans;
    }
};