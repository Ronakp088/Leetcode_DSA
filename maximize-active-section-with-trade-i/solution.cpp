class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        string t = "1" + s + "1";
        int m = t.size();

        int ones = 0;
        for(char c : s) if(c == '1') ones++;

        int maxGain = 0;
        int i = 0;
        while(i < m){
            int j = i;
            while(j < m && t[j] == t[i]) j++;
            if(t[i] == '1' && i != 0 && j != m){
                int prevLen = 0, k = i-1, kk = i-1;
                while(kk >= 0 && t[kk] == t[i-1]) { prevLen++; kk--; }
                int nextLen = 0, jj = j;
                while(jj < m && t[jj] == t[j]) { nextLen++; jj++; }
                if(t[i-1] == '0' && t[j] == '0'){
                    maxGain = max(maxGain, prevLen + nextLen);
                }
            }
            i = j;
        }

        return ones + maxGain;
    }
};