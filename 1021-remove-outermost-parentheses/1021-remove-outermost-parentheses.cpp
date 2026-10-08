class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt1 = 0;
        int p1 = 0;
        int p2 = 0;
        vector<char> ans;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt1++;
                p2++;
            }
            if (s[i] == ')') {
                cnt1--;
                p2++;
            }
            if (cnt1 == 0) {
                p2--;
                p1++;
                while (p1 < p2) {
                    ans.push_back(s[p1]);
                    p1++;
                }
                p2++;
                p1 = p2;
            }
        }
        return string(ans.begin(), ans.end());
    }
};