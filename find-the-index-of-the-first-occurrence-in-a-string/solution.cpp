class Solution {
public:
    int strStr(string haystack, string needle) {
        char ch = needle[0];
        int n = needle.size();
        if(haystack.size()<n) return -1;
        for(int i=0;i<=haystack.size()-n;i++){
            if(haystack[i] != ch) continue;
            else{
                if(haystack.substr(i,n) == needle) return i;
            }
        }
        return -1;
    }
};