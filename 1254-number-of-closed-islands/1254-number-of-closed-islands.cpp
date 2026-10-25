class Solution {
public:
    void dfs(int x ,int y ,vector<vector<int>> & grid){
        int n = grid.size();
        int m =  grid[0].size();
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        for(int i =0;i<4;i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(grid[nx][ny] == 0){
                grid[nx][ny] =1;
                dfs(nx,ny,grid);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i =0;i<n;i++){
            if(grid[i][0] == 0){
                grid[i][0] = 1;
                dfs(i,0,grid);
            }
            if(grid[i][m-1] == 0){
                grid[i][m-1] = 1;
                dfs(i,m-1,grid);
            }
        }
        for(int i =0;i<m;i++){
            if(grid[0][i] == 0){
                grid[0][i] = 1;
                dfs(0,i,grid); 
            }
            if(grid[n-1][i] == 0){
                grid[n-1][i] = 1;
                dfs(n-1,i,grid);
            }
        }
        int ans =0;
        for(int i = 1;i<n-1;i++){
            for(int j =1;j<m-1;j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};