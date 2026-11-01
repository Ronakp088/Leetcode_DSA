class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k+1,1e9));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        dist[0][1] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto [d, u , cnt]  = pq.top();
            pq.pop();
            if(d > dist[u][cnt]) continue;
            if(u == n-1) return d;
            for(auto[v,w] : adj[u]){
                int ncnt = (labels[u] == labels[v]) ? cnt +1 : 1;
                if(ncnt > k) continue;
                if(d + w < dist[v][ncnt]){
                    dist[v][ncnt] = d+w;
                    pq.push({dist[v][ncnt],v,ncnt});
                }
            }
        }
        return -1;
    }
};