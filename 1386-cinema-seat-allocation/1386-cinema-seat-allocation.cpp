class Solution {
public:
    int maxNumberOfFamilies(int k, vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> v;
        for (int i = 0; i < n; i++) {
            int row = nums[i][0];
            int t = nums[i][1];
            if (v.find(row) == v.end()) {
                v[row] = vector<int>(3, 1);
            }
            if (t == 2 || t == 3) {
                v[row][0]--;
            }
            else if (t == 4 || t == 5) {
                v[row][0]--;
                v[row][1]--;
            }
            else if (t == 6 || t == 7) {
                v[row][1]--;
                v[row][2]--;
            }
            else if (t == 8 || t == 9) {
                v[row][2]--;
            }
        }

        int ans = 2 * (k - v.size());
        for (auto &p : v) {
            vector<int>& row = p.second;
            if (row[0] == 1 && row[1] == 1 && row[2] == 1)ans += 2;
            else if (row[1] == 0 && row[0] == 1 && row[2] == 1)ans++;
            else if (row[0] == 0 && row[1] == 0 && row[2] == 1)ans++;
            else if (row[0] == 1 && row[1] == 0 && row[2] == 0)ans++;
            else if (row[2] == 1 && row[1] == 1 && row[0] == 0)ans++;
            else {
                int cnt = 0;

                for (int j = 0; j < 3; j++) {
                    if (row[j] > 0)
                        cnt++;
                }
                if (cnt >= 2)
                    cnt--;
                ans += cnt;
            }
        }

        return ans;
    }
};