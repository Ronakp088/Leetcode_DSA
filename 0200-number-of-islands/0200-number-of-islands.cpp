class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); // row
        int m = grid[0].size(); // column
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(grid,visited,i,j);
                }
            }
        }

        return ans;
    }
    void dfs(vector<vector<char>>& grid ,vector<vector<int>>& visited, int i,int j){
        visited[i][j] =1;
        int n = grid.size();
        int m = grid[0].size();
        if(j-1 >=0 && !visited[i][j-1] && grid[i][j-1] == '1'){
            dfs(grid,visited,i,j-1);
        } // left
        if(j+1 < m && !visited[i][j+1] && grid[i][j+1] == '1'){
            dfs(grid,visited,i,j+1);
        }// right
        if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == '1'){
            dfs(grid,visited,i-1,j);
        }//up
        if(i+1 < n && !visited[i+1][j] && grid[i+1][j] == '1'){
            dfs(grid,visited,i+1,j);
        }// down
    }
};