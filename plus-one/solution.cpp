class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> st;
        for(int i=0;i<digits.size();i++){
            st.push(digits[i]);
        }
        vector<int> ans ;
        int carry =1;
        while(!st.empty()){
            if(st.top()+carry == 10){
                ans.push_back(0);
                st.pop();
                }
                else {
                    ans.push_back(st.top()+carry);
                    carry = 0;
                    st.pop();
        }
        }
        if(ans[ans.size()-1]== 0) ans .push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};