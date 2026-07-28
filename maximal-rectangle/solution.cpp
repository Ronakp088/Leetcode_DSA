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
    int largestRectangleArea(vector<int>& arr) {
        vector<int> nse = FindNSE(arr);
        vector<int> pse = FindPSE(arr);
        int MaxArea =0;
        for(int i=0;i<arr.size();i++){
            int length = nse[i]-pse[i]-1;
            int area = length*(arr[i]);
            MaxArea = max(area,MaxArea);
        }
        return MaxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> PrefixSum(n, vector<int>(m)); 
        for(int j =0;j<=m-1;j++){
            int sum =0;
            for(int i=0;i<=n-1;i++){
                if(matrix[i][j] -'0' == 0) sum =0;
                else sum += (matrix[i][j] -'0');

                PrefixSum[i][j] = sum; 
            }
        }
        int MaxArea = 0;
        for(int i=0;i<=n-1;i++){
            MaxArea = max(MaxArea,largestRectangleArea(PrefixSum[i]));
        }
        return MaxArea;
    }
};