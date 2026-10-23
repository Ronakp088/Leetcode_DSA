class Disjointset{
    public:
    vector<int> rank,parent;
    Disjointset(int n){
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
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return ;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int cntextras = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUpar(u) == ds.findUpar(v)) cntextras++;
            else{
                ds.unionByrank(u,v);
            }
        }
        int cntC =0;
        for(int i =0;i<n;i++){
            if(ds.parent[i] == i) cntC++;
        }
        if(cntextras >= cntC-1) return cntC-1;

        return -1;
    }
};