class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = (*min_element(strs.begin(), strs.end())).size();
        string ans = "";
        int cnt = 1;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (strs[i][j] != strs[i + 1][j]) {
                    cnt = 0;
                    break;
                }
            }
            if (cnt == 1) {
                ans += strs[0][j];
            }
        }
        return ans;
    }
};