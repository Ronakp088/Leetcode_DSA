class Solution {
public:
    int numEnclaves(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> visi(n, vector<int> (m,0));
        queue<pair<int,int>> q;
        for(int i =0;i<m;i++){
            if(nums[0][i] == 1){
                visi[0][i] = 2;
                q.push({0,i});
            }
            if(nums[n-1][i] == 1){
                visi[n-1][i] = 2;
                q.push({n-1,i});
            }
        }
        for(int i = 1;i<= n-2;i++){
            if(nums[i][0] == 1){
                visi[i][0] = 2;
                q.push({i,0});
            }
            if(nums[i][m-1] == 1){
                visi[i][m-1] = 2;
                q.push({i,m-1});
            }
        }
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,-1,0,+1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i =0;i<4;i++){
                int nx = x + delrow[i];
                int ny = y + delcol[i];
                if( nx >= 0 && nx < n && ny >=0 && ny < m && visi[nx][ny] == 0 && nums[nx][ny]  == 1){
                    visi[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(visi[i][j] == 0 && nums[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};