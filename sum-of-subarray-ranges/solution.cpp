class Solution {
public:
    vector<int> FindNSE(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> FindPSE(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> FindNGE(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> FindPGE(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& arr) {
        int mod = (int)(1e9 + 7);
        vector<int> nse = FindNSE(arr);
        vector<int> pse = FindPSE(arr);
        vector<int> nge = FindNGE(arr);
        vector<int> pge = FindPGE(arr);
        long long total = 0;
        for (int i = 0; i < arr.size(); i++) {
            int rightS = nse[i] - i;
            int leftS = i - pse[i];
            int rightG = nge[i] - i;
            int leftG = i - pge[i];
            long long Max = rightG * (long long)leftG * arr[i];
            long long Min = rightS * (long long)leftS * arr[i];
            total += Max - Min;
        }
        return total;
    }
};