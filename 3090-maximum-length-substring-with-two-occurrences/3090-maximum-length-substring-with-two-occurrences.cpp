class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<int,int> mp;
        int ans =0;
        int j =0;
        int i =0;
        while(i<n){
            if(mp[s[i]] < 2){
                mp[s[i]]++;
                ans = max(ans,i-j+1);
                i++;
            }
            else{
                mp[s[j]]--;
                j++;
            }
        }
        return ans;
    }
};