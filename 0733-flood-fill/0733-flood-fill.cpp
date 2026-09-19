class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& visited,int i,int j,int color,int prev){
        int n = image.size();
        int m = image[0].size();
        if( i < 0 || j < 0 || i == n || j == m ) return;
        if(image[i][j] == prev && !visited[i][j]){
        visited[i][j] = 1;
        image[i][j] = color;
        dfs(image,visited,i-1,j,color, prev);
        dfs(image,visited,i+1,j,color, prev);
        dfs(image,visited,i,j-1,color, prev);
        dfs(image,visited,i,j+1,color, prev);
        }
        else {
            visited[i][j] = 1;
            return;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); // row
        int m = image[0].size(); // column
        vector<vector<int>> visited(n, vector<int>(m,0));
        int prev = image[sr][sc];
        dfs(image,visited,sr,sc,color,prev);

        return image;
    }
};