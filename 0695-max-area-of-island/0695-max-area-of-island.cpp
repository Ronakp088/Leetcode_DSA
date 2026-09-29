class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MaxArea = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int dir1[] = {-1, 0, +1, 0};
        int dir2[] = {0, -1, 0, +1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    int temp = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int t = q.front().second;
                        temp++;
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int nr = r + dir1[i];
                            int nt = t + dir2[i];
                            if (nr >= 0 && nt >= 0 && nr < n && nt < m) {
                                if (grid[nr][nt] == 1 && !vis[nr][nt]){
                                    vis[nr][nt] = 1;
                                    q.push({nr, nt});
                                }
                            }
                        }
                    }
                    MaxArea = max(temp, MaxArea);
                }
            }
        }

        return MaxArea;
    }
};
/*
1 1 0 0 0 
1 1 0 0 0 
0 0 0 1 1 
0 0 0 1 1

*/