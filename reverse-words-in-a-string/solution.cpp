class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp ="" ;// this is temp string
        string ans ="" ;//final ans
        for(int i=n-1;i>=0;i--){
            if(s[i] != ' '){
                temp += s[i];
                if(i == 0 && s[i] != ' '){
                 reverse(temp.begin(),temp.end());
                ans += temp;
            }
            }
            else if(s[i] == ' ' && temp != ""){
                reverse(temp.begin(),temp.end());
                ans += temp;
                 ans += " ";
                temp = "";
            }
        }
         if( ans[ans.size()-1] == ' '){
                ans = string(ans.begin(),ans.end()-1);
            }
         return ans;
    }
};