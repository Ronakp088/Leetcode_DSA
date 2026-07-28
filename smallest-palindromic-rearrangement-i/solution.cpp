class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int arr[26] = {0};
        for(int i= 0;i<n/2;i++){
            arr[s[i]-'a']++;
        }
       int j =0;
        for(int i=0;i<26;i++){
            while(arr[i]-- >0){
                s[j++] = (char)(i + 'a');
            }
        }
        for(int i=0; i<n/2;i++){
            s[n-i-1] =s[i];
        }
        return s;
    }
};