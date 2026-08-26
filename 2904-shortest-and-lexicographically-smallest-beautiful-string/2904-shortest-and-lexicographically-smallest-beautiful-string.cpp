class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l =0;
        int r =0;
        int cnt = 0;
        string ans = "";
        while(r<n){
            if( s[r] == '1') cnt++;
            if( cnt > k){
                while( l <= r && cnt > k){
                    if( s[l] == '1')cnt --;
                    l++;
                }
            }

            if( cnt == k){
                if( s[l] == '0') while( s[l] != '1') l++;
                if( ans == ""){
                    ans = s.substr(l,r-l+1);
                }
                else {
                    string temp = s.substr(l,r-l+1);
                    if( ans.size() > r-l+1) ans = temp;
                    else if( ans.size() == r-l+1){
                        int i = 0;
                        while( i < ans.size() && ans[i] == temp[i]){
                            i++;
                        }
                        if(ans[i] == '1') ans = temp;
                    }
                }
              //if( s[l] == '0') while( s[l] != '1') l++;
              r++;
                
            }
            if(cnt < k){
                r++;
            }
        }

        return ans;
    }
};