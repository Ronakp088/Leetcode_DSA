class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};
        int n = s.size();
        int r = 0;
        int l = 0;
        int maxf = 0;
        int maxlen = 0;

        while(r<n){
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);
            int change = (r-l+1) - maxf;
            if(change > k) {
                hash[s[l] - 'A']--;
                l++;
                // maxf = *max_element(hash, hash+26);
                // change = (r-l+1) - maxf;
            }
            if(change <= k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};