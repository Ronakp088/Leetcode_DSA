class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<char,int> check;
        int MaxSize = 0;
        for(int r=0;r<s.size();r++){
            if(check.count(s[r]) && check[s[r]] >= l) l = check[s[r]] +1; // uss duplicate ke just next wale pe jump
            check[s[r]] = r;
            MaxSize = max(MaxSize,r-l+1);
        }

        return MaxSize;
    }
};