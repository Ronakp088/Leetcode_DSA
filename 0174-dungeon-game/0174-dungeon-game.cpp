class Solution {
public:
    int f(int i,int j,int health,vector<vector<int>>& dungeon,vector<vector<int>>& dp){
        int n = dungeon.size();
        int m = dungeon[0].size();
        health = max(1, health-dungeon[i][j]);
        if(i == 0 && j == 0) return health;
        if(health >= dp[i][j]) return INT_MAX;
        dp[i][j] = health;
        int up = INT_MAX;
        if(i-1 >= 0) up = f(i-1,j,health,dungeon,dp);
        int left = INT_MAX;
        if(j-1 >= 0) left = f(i,j-1,health,dungeon,dp);

        return min(up,left);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        if(n == 1 && m == 1){
            if(dungeon[0][0] >= 0) return 1;
            else return -dungeon[0][0] +1;
        }
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        return f(n-1, m-1,1,dungeon,dp);
    }
};