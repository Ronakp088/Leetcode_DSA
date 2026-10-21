class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> time(n,1e18);
        vector<int> ways(n,0);
        time[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            int node = pq.top().second;
            long long ot = pq.top().first;
            pq.pop();
            if(ot > time[node]) continue;

            for(auto it: adj[node]){
                long long nt = ot + it.second;
                int v = it.first;
                if(nt < time[v]){
                    ways[v] = ways[node];
                    time[v] = nt;
                    pq.push({nt,v});
                }
                else if(nt == time[v]){
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];

    }
};