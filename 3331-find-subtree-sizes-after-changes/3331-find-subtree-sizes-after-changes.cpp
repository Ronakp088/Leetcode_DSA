class Solution {
public:

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n =parent.size();
        vector<vector<int>> adj(n);
        for(int i =1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<int> np(parent.begin(),parent.end());
        vector<int> last(26,-1);
        function<void(int)> dfs = [&](int u){
            int c = s[u]-'a';
            int prev = last[c];
            if(prev != -1)np[u] = prev;
            last[c] = u;
            for(int v : adj[u]) dfs(v);
            last[c] = prev;
        };
        dfs(0);
        vector<vector<int>> nadj(n);
        for(int i = 1;i<n;i++) nadj[np[i]].push_back(i);
        vector<int> ans(n);
        function<int(int)> size = [&](int u){
            int sz = 1;
            for(int v: nadj[u]) sz += size(v);
            return ans[u] = sz; 
        };
        size(0);

        return ans;

    }
};