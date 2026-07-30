class Solution {
public:
    int distance(vector<int>& t) { return t[0] * t[0] + t[1] * t[1]; }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            pair<int, vector<int>> pi = {distance(points[i]), points[i]};
            pq.push(pi);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};