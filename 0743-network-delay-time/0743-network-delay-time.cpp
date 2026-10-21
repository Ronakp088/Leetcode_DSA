class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        vector<int> time(n,1e9);
        time[k-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        // {time,node}
        pq.push({0,k-1});
        while(!pq.empty()){
            auto r = pq.top();
            int u = r.second;
            int ot = r.first;
            pq.pop();
            for(auto it : adj[u]){
                int v = it.first;
                int nt = ot + it.second;
                if(nt < time[v]){
                    time[v] = nt;
                    pq.push({nt,v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i =0;i<n;i++){
            if(time[i] == 1e9) return -1;
            else ans = max(ans,time[i]);
        }

        return ans;
    }
};