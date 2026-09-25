class Solution {
    private:
    bool dfs(int i, vector<vector<int>> &adj, vector<int>& visi, vector<int>&path){
        visi[i] = 1;
        path[i] = 1;
        for(int it : adj[i]){
            if(!visi[it]) {
                if(dfs(it, adj, visi, path) == true) return true;
            }
            else if(visi[it] == 1 && path[it] == 1) return true;
        }
        path[i] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        int v = edges.size();
        vector<int> ans;
        for(int i =0;i<v;i++){
        vector<int> visi(v,0);
        vector<int> path(v,0);
            if(dfs(i,edges,visi,path) == false) ans.push_back(i);
        }
        return ans;
    }
};