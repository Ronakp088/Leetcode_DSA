class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> bonus(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) bonus[i] += 1;
            }
        }

        vector<vector<int>> dp(n, vector<int>(budget + 1, 0));
        for (int j = items[0][1]; j <= budget; j++) {
            dp[0][j] = j / items[0][1] + bonus[0];
        }

        for (int i = 1; i < n; i++) {
            int f = items[i][0], p = items[i][1];
            for (int j = 0; j <= budget; j++) {
                dp[i][j] = dp[i - 1][j];
                if (p > j) continue;
                dp[i][j] = max({dp[i][j],
                                dp[i - 1][j - p] + bonus[i] + 1,
                                dp[i][j - p] + 1});
            }
        }

        return dp[n - 1][budget];
    }
};