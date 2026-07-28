class Solution {
public:
    void parenthesisMaker(int open,int close,int n,string temp,vector<string>& ans){
        if(temp.size() == n*2){
            ans.push_back(temp);
            return;
        }
        if(open < n ){
            temp.push_back('(');
            parenthesisMaker(open+1,close,n,temp,ans);
            temp.pop_back();
        }
        if(open > close){
            temp.push_back(')');
            parenthesisMaker(open,close+1,n,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        parenthesisMaker(0,0,n,temp,ans);
        return ans;
    }
};