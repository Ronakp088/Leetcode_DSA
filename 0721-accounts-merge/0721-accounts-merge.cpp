class DisjointSet{
public:
    vector<int> rank, parent;

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i =0;i<n+1;i++){
            parent[i] = i; 
        }
    }
    int findUpar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUpar(parent[node]);
    }

    void unionByrank(int u, int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pu == pv) return ;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mpp;
        for(int i =0;i<n;i++){
            for(int j =1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }
                else{
                    ds.unionByrank(i,mpp[mail]);
                }
            }
        }

        vector<string> mergemail[n];
        for(auto it: mpp){
            string mail = it.first;
            int node = ds.findUpar(it.second);
            mergemail[node].push_back(mail);
        }
        vector<vector<string>> ans;

        for(int i = 0;i<n;i++){
            if(mergemail[i].size() == 0) continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergemail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }


        return ans;
    }
};