class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<int,int> Map1;
        unordered_map<int,int> Map2;
        for(char c : s) Map1[c]++;
        for(char c : t) Map2[c]++;

        if(Map1 == Map2) return true;

        return false;
    }
};