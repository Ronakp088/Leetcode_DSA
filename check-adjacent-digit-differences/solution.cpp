class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for(int i =0;i<=n-2;i++){
            if(abs(s[i]-s[i+1]) >2) return false;
        }
        return true;
    }
};