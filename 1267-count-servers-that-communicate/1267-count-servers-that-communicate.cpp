class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    int r, c;

    bool validity(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int countServers(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int, int>> q;

        int cnt = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = -1;

                    int component = 0;

                    while (!q.empty()) {
                        int ni = q.front().first;
                        int nj = q.front().second;
                        q.pop();

                        component++;


                        for (int x = 0; x < c; x++) {
                            if (grid[ni][x] == 1) {
                                grid[ni][x] = -1;
                                q.push({ni, x});
                            }
                        }


                        for (int x = 0; x < r; x++) {
                            if (grid[x][nj] == 1) {
                                grid[x][nj] = -1;
                                q.push({x, nj});
                            }
                        }
                    }


                    if (component > 1) {
                        cnt += component;
                    }
                }
            }
        }

        return cnt;
    }
};