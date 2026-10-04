class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(i == n-1 && j == m-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int paths = 0;

        if(j+1 < m && obstacleGrid[i][j+1] == 0)
            paths += solve(i, j+1, obstacleGrid, dp);

        if(i+1 < n && obstacleGrid[i+1][j] == 0)
            paths += solve(i+1, j, obstacleGrid, dp);

        return dp[i][j] = paths;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, obstacleGrid, dp);
    }
};