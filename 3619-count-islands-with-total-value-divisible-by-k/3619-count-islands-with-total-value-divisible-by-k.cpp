class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,long long& cnt){
        int n = grid.size();
        int m = grid[0].size();
        cnt += grid[i][j];
        grid[i][j] = 0;
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        for(int k=0;k<4;k++){
            int nx = i + dirx[k];
            int ny = j + diry[k];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(grid[nx][ny] != 0) dfs(nx,ny,grid,cnt);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] != 0){
                    long long cnt =0;
                    dfs(i,j,grid,cnt);
                    if(cnt%k == 0) ans++;
                }
            }
        }
        return ans;

    }
};