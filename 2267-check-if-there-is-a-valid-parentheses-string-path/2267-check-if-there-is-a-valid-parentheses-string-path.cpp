class Solution {
public:
    bool check(vector<vector<char>>& grid,int i,int j,int cnt , vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(grid[i][j] == '(') cnt++;
        else cnt--;

        if(i == n-1 && j == m-1){
            if(cnt == 0) return  true;
            else return false;
        }
        if(cnt < 0) return false;

        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
        bool down = false;
        bool right = false;
        if(i+1 < n) down = check(grid,i+1,j,cnt , dp);
        if(j+1 < m) right = check(grid,i,j+1,cnt , dp);

        return dp[i][j][cnt] =  down || right;
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(m , vector<int>(m+n , -1)));
        return check(grid,0,0,cnt , dp);
    }
};