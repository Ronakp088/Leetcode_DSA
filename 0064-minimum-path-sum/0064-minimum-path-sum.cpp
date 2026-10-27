class Solution {
public:
    // int f(int i, int j ,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int up = INT_MAX;
    //     if(i-1 >= 0) up = f(i-1,j,grid,dp);
    //     int left = INT_MAX;
    //     if(j-1 >= 0) left = f(i,j-1,grid,dp);

    //     return dp[i][j] = min(up,left) + grid[i][j]; 
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        dp[0][0] = grid[0][0];
        if(n == 1 && m == 1) return grid[0][0];
        else if(n == 1 && m > 1){
            int sum1 = 0;
            for(int i =0;i<m;i++){
                sum1 += grid[0][i]; 
            }
            return sum1;
        }
        else if(n > 1 && m == 1){
            int sum2 = 0;
            for(int i =0;i<n;i++){
                sum2 += grid[i][0]; 
            }
            return sum2;
        }
        dp[0][1] = grid[0][0] + grid[0][1];
        dp[1][0] = grid[0][0] + grid[1][0];
        dp[1][1] = min(dp[0][1] + grid[1][1],dp[1][0] + grid[1][1]);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dp[i][j] != -1) continue;
                int up = INT_MAX;
                if(i-1 >= 0) up = dp[i-1][j];
                int left = INT_MAX;
                if(j-1 >= 0) left = dp[i][j-1];

                dp[i][j] = min(up,left) + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};