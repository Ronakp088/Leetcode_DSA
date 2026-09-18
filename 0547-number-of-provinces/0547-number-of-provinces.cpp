class Solution {
public:
    void dfs(int node,vector<vector<int>>& isconnected,vector<int>& vist){
        vist[node] = 1;
        for(int i = 0; i < isconnected.size(); i++){
            if(isconnected[node][i] == 1 && !vist[i])
                dfs(i, isconnected, vist);
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n = isconnected.size();
        vector<int> vist(n,0);
        int ans =0;
        for(int i =0;i<n;i++){
           if(!vist[i]) {
            dfs(i,isconnected,vist);
            ans++;
           }
        }
        return ans;
    }
};