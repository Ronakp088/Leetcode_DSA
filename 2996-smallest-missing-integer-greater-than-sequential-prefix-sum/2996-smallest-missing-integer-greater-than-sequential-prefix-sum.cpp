class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0]+1;
        int sum = nums[0];
        int j = 1;
        while(j < n && nums[j]-nums[j-1] == 1 ){
            sum += nums[j];
            j++;
        }
        unordered_set<int> st;
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans = sum;
        while(st.find(ans) != st.end()){
            ans++;
        }

        return ans;
    }
};