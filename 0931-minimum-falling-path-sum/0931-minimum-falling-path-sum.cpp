class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
         int n = nums.size();
        if(n == 1) return nums[0][0];
        vector<vector<int>> dp(n, vector<int>(n,1e9));
        for(int i =0;i<n;i++){
            dp[0][i] = nums[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                if(j == 0){
                    int down = dp[i-1][j];
                    int right = INT_MAX;
                    if(j+1<n) right = dp[i-1][j+1];
                    dp[i][j] = nums[i][j] + min(down,right); 
                }
                else if( j == n-1){
                    int d = dp[i-1][j];
                    int left = dp[i-1][j-1];
                    dp[i][j] = nums[i][j] + min(d,left);
                }
                else if( j > 0 && j < n-1){
                    int D = dp[i-1][j];
                    int R = dp[i-1][j+1];
                    int L = dp[i-1][j-1];
                    dp[i][j] = nums[i][j] + min(D,min(R,L));
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