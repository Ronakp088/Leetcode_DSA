class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> idx(26);
        vector<bool> seen(
            26); // ye dekhne ke liye ki peheele wo char aaya hai ya nahi
        string ans;
        for (int i = 0; i < s.size(); i++)
            idx[s[i] - 'a'] = i;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (seen[c - 'a'])
                continue; // pehele hi aagaya hai
            while (ans.size() && ans.back() > c && idx[ans.back() - 'a'] > i) {
                seen[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            seen[c - 'a'] = 1;
        }
        return ans;
    }
};