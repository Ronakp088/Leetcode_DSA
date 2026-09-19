class Solution {
public:
    void dfs(vector<vector<int>>& grid,int& ans, queue<pair<int,int>> st){
        int n = grid.size();
        int m = grid[0].size();
        int flag =0;
        int level = st.size();
        for(int k =0;k<level;k++){
            int i = st.front().first;
            int j = st.front().second;
            grid[i][j] = 0;
            st.pop();
            if(i-1 >=0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                st.push({i-1,j});
                flag =1;
            }//up
            if(i+1 < n && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                st.push({i+1,j});
                flag =1;
            }//down
            if(j-1 >=0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                st.push({i,j-1});
                flag =1;
            }//left
            if(j+1  < m  && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                st.push({i,j+1});
                flag =1;
            }//right
        }
        if(flag == 1) ans++;
        if(!st.empty()) dfs(grid,ans,st);
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // row
        int m = grid[0].size(); // column
        /* 0 = empty
        1= fresh
        2 = rotten
         */
        queue<pair<int,int>> st;
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 2){
                    st.push({i,j});
                }
            }
        }
        dfs(grid,ans,st);

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};