class Solution {
public:
    string addBinary(string a, string b) {
        stack<int> st;
        int i = a.size()-1, j = b.size()-1, carry = 0;
        
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0) sum += (a[i]-'0');
            if(j >= 0) sum += (b[j]-'0');
            st.push(sum % 2);
            carry = sum / 2;
            i--; j--;
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top()+'0');
            st.pop();
        }
        return ans;
    }
};