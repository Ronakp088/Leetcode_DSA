class Solution {
public:
   bool hasValidPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;
    vector<vector<int>> visi(n, vector<int>(m,0));

    q.push({0,0});
    visi[0][0] = 1;

    while(!q.empty()){
        int r = q.front().first;
        int t = q.front().second;
        q.pop();

        if(r == n-1 && t == m-1)
            return true;

        if(grid[r][t] == 1){
            if(t+1 < m && !visi[r][t+1] &&
               (grid[r][t+1] == 1 || grid[r][t+1] == 3 || grid[r][t+1] == 5)){
                visi[r][t+1] = 1;
                q.push({r,t+1});
            }

            if(t-1 >= 0 && !visi[r][t-1] &&
               (grid[r][t-1] == 1 || grid[r][t-1] == 4 || grid[r][t-1] == 6)){
                visi[r][t-1] = 1;
                q.push({r,t-1});
            }
        }

        if(grid[r][t] == 2){
            if(r+1 < n && !visi[r+1][t] &&
               (grid[r+1][t] == 2 || grid[r+1][t] == 5 || grid[r+1][t] == 6)){
                visi[r+1][t] = 1;
                q.push({r+1,t});
            }

            if(r-1 >= 0 && !visi[r-1][t] &&
               (grid[r-1][t] == 2 || grid[r-1][t] == 3 || grid[r-1][t] == 4)){
                visi[r-1][t] = 1;
                q.push({r-1,t});
            }
        }

        if(grid[r][t] == 3){
            if(r+1 < n && !visi[r+1][t] &&
               (grid[r+1][t] == 2 || grid[r+1][t] == 5 || grid[r+1][t] == 6)){
                visi[r+1][t] = 1;
                q.push({r+1,t});
            }

            if(t-1 >= 0 && !visi[r][t-1] &&
               (grid[r][t-1] == 1 || grid[r][t-1] == 4 || grid[r][t-1] == 6)){
                visi[r][t-1] = 1;
                q.push({r,t-1});
            }
        }

        if(grid[r][t] == 4){
            if(r+1 < n && !visi[r+1][t] &&
               (grid[r+1][t] == 2 || grid[r+1][t] == 5 || grid[r+1][t] == 6)){
                visi[r+1][t] = 1;
                q.push({r+1,t});
            }

            if(t+1 < m && !visi[r][t+1] &&
               (grid[r][t+1] == 1 || grid[r][t+1] == 3 || grid[r][t+1] == 5)){
                visi[r][t+1] = 1;
                q.push({r,t+1});
            }
        }

        if(grid[r][t] == 5){
            if(r-1 >= 0 && !visi[r-1][t] &&
               (grid[r-1][t] == 2 || grid[r-1][t] == 3 || grid[r-1][t] == 4)){
                visi[r-1][t] = 1;
                q.push({r-1,t});
            }

            if(t-1 >= 0 && !visi[r][t-1] &&
               (grid[r][t-1] == 1 || grid[r][t-1] == 4 || grid[r][t-1] == 6)){
                visi[r][t-1] = 1;
                q.push({r,t-1});
            }
        }

        if(grid[r][t] == 6){
            if(r-1 >= 0 && !visi[r-1][t] &&
               (grid[r-1][t] == 2 || grid[r-1][t] == 3 || grid[r-1][t] == 4)){
                visi[r-1][t] = 1;
                q.push({r-1,t});
            }

            if(t+1 < m && !visi[r][t+1] &&
               (grid[r][t+1] == 1 || grid[r][t+1] == 3 || grid[r][t+1] == 5)){
                visi[r][t+1] = 1;
                q.push({r,t+1});
            }
        }
    }

    return false;
}
};