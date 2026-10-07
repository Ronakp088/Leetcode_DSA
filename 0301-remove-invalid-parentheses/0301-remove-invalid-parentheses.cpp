class Solution {
public:
    void solve(string s,vector<string>& ans, int scanst,int delst,char open, char close){
        int cnt =0;
        for(int i = scanst;i<s.size();i++){
            if(s[i] == open) cnt++;
            else if(s[i] == close) cnt--;
            if(cnt >= 0) continue;
            for(int j = delst;j<=i;j++){
                if(s[j] == close && (j == delst || s[j-1] != close)){
                    solve(s.substr(0,j)+s.substr(j+1),ans,i,j,open,close);
                }
            }
            return;
        }
        reverse(s.begin(),s.end());
        if(open == '('){
            solve(s,ans,0,0,')','(');
        }
        else ans.push_back(s);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        solve(s,ans,0,0,'(',')');
        return ans;
    }
};