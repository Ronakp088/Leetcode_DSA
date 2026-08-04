class Solution {
public:
    vector<int> partitionLabels(string s) {
       int n = s.size();
       vector<int> v(26,0);
       for(int i = n-1;i>=0;i--){
        if(v[s[i]-'a'] == 0){
            v[s[i] -'a'] = i;
        }
       }
        vector<int> ans;
       for(int i =0;i<n;i++){
        int st = i;
        int end = v[s[i]-'a'];
        for(int j =i; j<=end;j++){
            int check = v[s[j]-'a'];
            if(check > end) end = check;
        }
        ans.push_back(end-st+1);
        i = end;
       }
    return ans;
    }
};