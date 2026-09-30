class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i =0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        vector<int> temp;
        for(int i =0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            temp.push_back(t);
            for(auto it: adj[t]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(temp.size() == numCourses) return temp;

        return {};
    }
};