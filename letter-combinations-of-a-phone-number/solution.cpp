class Solution {
public:
    void backTrack(int idx,string& digits,unordered_map<char,string>& mpp,vector<string>& ans,string& temp){
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i< mpp[digits[idx]].size();i++){
        temp.push_back(mpp[digits[idx]][i]);
        backTrack(idx+1,digits,mpp,ans,temp);
        temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mpp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ans;
        string temp = "";

        backTrack(0,digits,mpp,ans,temp);

        return ans;
    }
};