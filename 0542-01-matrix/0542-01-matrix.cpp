class Solution {
public:
    // int bfs(vector<vector<int>>& mat,queue<pair<pair<int,int>,int>>& q,vector<vector<int>>& ans,vector<vector<int>>& visi){
    //     int n = mat.size();
    //     int m = mat[0].size();
    //     while(!q.empty()){
    //     int lvl = q.size();
    //     for(int i =0;i<lvl;i++){
    //         int x = q.front().first.first;
    //         int y = q.front().first.second;
    //         int t = q.front().second;
    //         if(mat[x][y] == 0) return t;
    //         else{
    //             if(x-1 >= 0) q.push({{x-1,y},t+1});
    //             if(x+1 < n) q.push({{x+1,y},t+1});
    //             if(y-1 >= 0) q.push({{x,y-1},t+1});
    //             if(y+1 < m) q.push({{x,y+1},t+1});
    //         }
    //         visi[x][y] =1;
    //         q.pop();
    //     }
    //     }

    //     return 0;
    // }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visi(n,vector<int> (m,0));
        vector<vector<int>> ans(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visi[i][j] =1;
                }
            }
        }

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans[x][y] = t;
            for(int i =0;i<4;i++){
                int nx = x+delrow[i];
                int ny = y+delcol[i];
                if(nx >= 0 && nx < n && ny >=0 && ny < m && !visi[nx][ny]) {
                    visi[nx][ny] =1;
                    q.push({{nx,ny},t+1});
                }
            }
        }
        
        return ans;
    }
};