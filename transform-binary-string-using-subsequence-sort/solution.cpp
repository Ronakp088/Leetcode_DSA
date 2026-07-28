class Solution {
public:
    bool check(vector<int>& prefOnes, string& temp, int cnt1, int n){
        int q = 0;
        int ones = 0;
        for(int i=0;i<n;i++){
            if(temp[i] == '?') q++;
            else if(temp[i] - '0' == 1) ones++;
        }
        int need = cnt1 - ones;
        if(need < 0 || need > q) return false;

        int qDone = 0;
        int run = 0;
        for(int i=0;i<n;i++){
            int val;
            if(temp[i] - '0' == 1) val = 1;
            else if(temp[i] - '0' == 0) val = 0;
            else{
                qDone++;
                if(qDone > q - need) val = 1;
                else val = 0;
            }
            run += val;
            if(run > prefOnes[i]) return false;
        }
        return true;
    }

    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> prefOnes(n);
        int cnt1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] - '0' == 1) cnt1++;
            prefOnes[i] = cnt1;
        }

        vector<bool> ans;
        for(int i=0;i<strs.size();i++){
            ans.push_back(check(prefOnes, strs[i], cnt1, n));
        }
        return ans;
    }
};