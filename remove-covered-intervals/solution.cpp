class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 1)
            return 1;
        int ans = n;
        int p = 1;
        int i = 0;
        while (p < n) {
            if (intervals[p][0] == intervals[i][0]) {
                ans--;
                p++;
                i++;
            } else {
                if (intervals[p][1] <= intervals[i][1]) {
                    ans--;
                    p++;
                } else {
                    i = p;
                    p++;
                }
            }
        }
        return ans;
    }
};