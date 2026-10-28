class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0][0];
        vector<vector<int>> dp(n, vector<int>(n,-1));
        dp[0][0] = nums[0][0];
        for(int i = 1;i<n;i++){
            for(int j = 0;j<=i;j++){
                if(j == 0){
                    dp[i][j] = nums[i][j] + dp[i-1][0];
                }
                else if( j == i){
                    dp[i][j] = nums[i][j] + dp[i-1][i-1];
                }
                else if( j > 0 && j < i){
                    int left = dp[i-1][j-1];
                    int right = dp[i-1][j];
                    dp[i][j] = nums[i][j] + min(right,left);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }

        return ans;
    }
};