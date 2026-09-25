class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n,-1);
        queue<pair<int,int>> q;
       for(int i =0;i<n;i++){
        if(color[i] == -1){ q.push({i,0});
        color[i] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int adjnode : graph[node]){
                if(color[adjnode] == -1){
                    if(c == 0){
                        color[adjnode] = 1;
                        q.push({adjnode,1});
                    }
                    else{
                        color[adjnode]= 0;
                        q.push({adjnode,0});
                    }
                }
                else if(color[adjnode] == c) return false;
            }
        }
        }
        }

        return true;
    }
};