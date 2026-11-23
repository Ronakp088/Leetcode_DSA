class Solution {
public:
    bool f(int i, int j,string &s, string &p,vector<vector<int>>& dp){
        if(i <0 && j < 0) return true;
        else if(i < 0 && j >= 0){
            for(int k = 0;k<=j;k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        else if(j<0 && i>=0) return false;
        if(dp[i][j] != -1) return  dp[i][j];

        if(s[i] == p[j]) return dp[i][j] = f(i-1,j-1,s,p,dp);
        else if(p[j] == '?') return dp[i][j] = f(i-1,j-1,s,p,dp);
        else{
            if(p[j] == '*'){
                bool t = false;
                for(int k = 0;k<=i+1;k++){
                    t  = t || f(i-k,j-1,s,p,dp);
                }
                return dp[i][j] = t;
            }
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)); 
        return f(n-1,m-1,s,p,dp);
    }
};