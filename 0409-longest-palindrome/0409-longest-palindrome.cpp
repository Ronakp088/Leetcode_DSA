class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        vector<int> v1(52, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] - 'a' < 0) {
                v1[s[i] - 'A' + 26]++;
            } else {
                v1[s[i] - 'a']++;
            }
        }
        int flag = 0;
        int cnt = 0;

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] == 1)
                flag = 1;

            else if (v1[i] % 2 == 1) {
                cnt += v1[i] - 1;
                flag =1;
            } else
                cnt += v1[i];
        }
        return cnt + flag;
    }
};