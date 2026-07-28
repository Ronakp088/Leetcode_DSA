class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size();
        int n2 = s.size();
        int i = n1-1;
        int j = n2-1;
        int ans = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i>=0 && j>=0){
            if(s[j] >= g[i]){
                ans++;
                i--;
                j--;
            }
            else{
                i--;
            }
        }
        return ans;
    }
};