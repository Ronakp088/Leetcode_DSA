class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }
        vector<int> stops(n, 1e9);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {src, 0}});
        while(!pq.empty()){
            auto t = pq.top();
            int price = t.first;
            int u = t.second.first;
            int cnt = t.second.second;
            pq.pop();
            if(u == dst) return price;
            if(cnt > k) continue;
            if(stops[u] <= cnt) continue;
            stops[u] = cnt;
            cnt++;
            for(auto it: adj[u]){
                int v = it.first;
                int wt = it.second;
                pq.push({price + wt, {v, cnt}});
            }
        }
        return -1;
    }
};