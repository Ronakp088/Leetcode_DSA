class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string temp = "";
        int n = s.size();
        int cntx =0;
        int cnty =0;
        for(int i=0;i<n;i++){
            if(s[i] == x) cntx++;
            else if(s[i] == y) cnty++;
            else{
                temp.push_back(s[i]);
            }
        }
        string ans = "";
        while(cnty>0){
            ans.push_back(y);
            cnty--;
        }
        ans += temp;
        
        while(cntx>0){
            ans.push_back(x);
            cntx--;
        }
       return ans; 
    }
};