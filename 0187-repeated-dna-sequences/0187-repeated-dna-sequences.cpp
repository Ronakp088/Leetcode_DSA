class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string,int> mp;
        vector<string> v;
        for(int i = 0;i<=n-10;i++){
            string temp = s.substr(i,10);
            mp[temp]++;
        }
        for(auto it: mp){
            if(it.second >= 2) v.push_back(it.first);
        }

        return v;
    }
};