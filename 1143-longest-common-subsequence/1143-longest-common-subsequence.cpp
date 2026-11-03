class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i =0;i<m;i++){
            if(s1[0] == s2[i] || (i>0 && dp[0][i-1] == 1)) dp[0][i] = 1;
        }
        for(int i =0;i<n;i++){
            if(s2[0] == s1[i] || (i>0 && dp[i-1][0] == 1)) dp[i][0] = 1;
        }
        
        for(int i =1;i<n;i++){
            for(int j=1;j<m;j++){
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};