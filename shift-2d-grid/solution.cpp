class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int Size = n * m;
        k = k % Size;
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int Newidx = i * m + j + k;
                int Newrow = (Newidx / m) % n;
                int Newcolumn = Newidx % m;
                ans[Newrow][Newcolumn] = grid[i][j];
            }
        }
        return ans;
    }
};