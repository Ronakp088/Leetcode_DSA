class Solution {
public:
    bool check( unordered_map<int,int>& Map, int target){
        for(auto& it: Map){
            if(it.second == target) return true;
        }
        return false;
    }
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> Map;
        for(int i=0;i<s.size();i++){
            if(Map.find(s[i]) != Map.end()){
                if(Map[s[i]] == t[i]) continue;
                else return false;
            }
            else if(check(Map,t[i])) return false;
            else Map[s[i]] = t[i];
        }
        return true;
    }
};