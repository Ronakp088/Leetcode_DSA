class Solution {
public:
    void dfs(vector<vector<int>>& isconnected , vector<int>& visited, int i){
        visited[i] = 1;
        for(int j =0;j<isconnected.size();j++){
            if(!visited[j] && isconnected[i][j] == 1){
                dfs(isconnected,visited,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n = isconnected.size();
        int ans =0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(isconnected,visited,i);
            }
        }
        return ans;
    }
};