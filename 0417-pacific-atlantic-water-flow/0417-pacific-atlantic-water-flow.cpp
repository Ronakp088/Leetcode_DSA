class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));

        queue<pair<int,int>> qp;
        queue<pair<int,int>> qa;

        for(int i = 0; i < n; i++){
            pac[i][0] = 1;
            atl[i][m-1] = 1;

            qp.push({i,0});
            qa.push({i,m-1});
        }

        for(int j = 0; j < m; j++){
            pac[0][j] = 1;
            atl[n-1][j] = 1;

            qp.push({0,j});
            qa.push({n-1,j});
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        while(!qp.empty()){
            auto [r,c] = qp.front();
            qp.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   !pac[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]){

                    pac[nr][nc] = 1;
                    qp.push({nr,nc});
                }
            }
        }

        while(!qa.empty()){
            auto [r,c] = qa.front();
            qa.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   !atl[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]){

                    atl[nr][nc] = 1;
                    qa.push({nr,nc});
                }
            }
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};