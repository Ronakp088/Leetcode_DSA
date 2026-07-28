class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int> m1;
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
        }
        unordered_map<int,int> check;
        for(int i=0;i<t.size();i++){
            if(m1.find(t[i]) == m1.end()  || check[t[i]] == m1[t[i]]) return t[i]; 
            else check[t[i]]++;
        }

        return {};
    }
};