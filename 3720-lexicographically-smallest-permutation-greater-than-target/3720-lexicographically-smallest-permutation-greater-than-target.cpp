class Solution {
public:
    string bakika(const int * freq){
        string ans;
        for(int i =0;i<26;i++){
            ans.append(freq[i],'a'+i);
        }
        return ans;
    }
    string lexGreaterPermutation(string s, string target) {
        int freq[26]{0};
        for(char& c:s){
            freq[c-'a']++;
        }
        for(char& c:target){
            freq[c-'a']--;
        }
        for(int i =s.size()-1;i>=0;i--){
            int t = target[i]-'a';
            freq[t]++;

            if(*min_element(freq,freq+26) < 0) continue;

            for(int j = t+1;j<26;j++){
                if(freq[j]){
                    freq[j]--;
                    target[i] = 'a' + j;
                    target.resize(i+1);
                    return target + bakika(freq);
                }
            }
        }
        return "";
    }
};