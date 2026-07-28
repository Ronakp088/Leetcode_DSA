class Solution {
public:
    unordered_map<string,bool> memo; // memoriztion ke liye 
    bool check(string& s, unordered_set<string>& st){
        if(s.empty()) return true;
        if(memo.find(s) != memo.end()){
            return memo[s];
        }
        for(int i=0;i<s.size();i++){
           if(st.find(s.substr(0,i+1)) != st.end()){

                string temp = s;
                    temp.erase(0,i+1);
                    if(check(temp,st)){
                       return  memo[s] = true;
                    }
                }
        }
        return memo[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        return check(s,st);
    }
};