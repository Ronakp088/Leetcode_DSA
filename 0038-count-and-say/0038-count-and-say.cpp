class Solution {
public:
    string s = "";
    string countAndSay(int n) {
        if (n == 1) {
            s = "1";
            return s;
        }
        countAndSay(n - 1);
        int i = 0;
        while (i < s.size()) {
            int f = s[i] - '0';
            int j = i;
            while (j < s.size() && s[j] - '0' == f)
                j++;
            int cnt = j - i;
            s.replace(i, cnt, to_string(cnt) + to_string(f));
            i += to_string(cnt).size() + 1;
        }

        return s;
    }
};