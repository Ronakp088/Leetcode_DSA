class Solution {
public:
   vector<int> FindNSE(vector<int>& arr){
    vector<int> ans(arr.size());
    stack<int> st; 
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        ans[i] = st.empty()?arr.size():st.top();
        st.push(i);
    }
    return ans;
    }
    vector<int> FindPSE(vector<int>& arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod = (int)(1e9 + 7);
        vector<int> nse = FindNSE(arr);
        vector<int> pse = FindPSE(arr);
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int right = nse[i] - i;
            int left = i-pse[i];

            ans = (ans + (right*left*1LL*arr[i])%mod)%mod; 
        }
        return ans;
    }
};