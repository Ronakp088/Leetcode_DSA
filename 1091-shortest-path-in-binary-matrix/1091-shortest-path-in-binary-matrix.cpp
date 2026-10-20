class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<int> adj[n*n];
        int drx[] = {0,0,1,-1,1,1,-1,-1};
        int dry[] = {1,-1,0,0,1,-1,1,-1};
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 0){
                    for(int k = 0;k<8;k++){
                        int nx = i + drx[k];
                        int ny = j + dry[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                            if(grid[nx][ny] == 0){
                                adj[i*n + j].push_back((nx)*n + ny);
                            }
                        }
                    }
                }
            }
        }
        
        vector<int> dis(n*n , 1e9);
        dis[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(distance != dis[node]) continue;
            for(auto it: adj[node]){
                int v = it;
                int wt = 1;
                if(wt + distance < dis[v]){
                    dis[v] = wt + distance;
                    pq.push({dis[v],v});
                }
            }
        }
        if(dis[n*n -1 ] == 1e9) return -1;
        
        return dis[n*n -1] + 1 ;
    }
};