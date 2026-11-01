class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
            int n = arr.size();
            int mod = 1e9 + 7;
            vector<int> prev(target+1),curr(target+1);

            prev[0] = 1;
            if(arr[0] == 0) prev[0] = 2;
            else if(arr[0] <= target) prev[arr[0]] = 1;

            for(int i = 1; i < n; i++){
                for(int j = 0; j <= target; j++){
                    int notTake = prev[j];
                    int take = 0;
                    if(arr[i] <= j) take = prev[j-arr[i]];

                    curr[j] = (take + notTake) % mod;
                }
                prev = curr;
            }
            return prev[target];
        }
        
    int countPartitions(vector<int>& arr, int diff) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum - diff < 0 || (sum - diff) % 2 != 0) return 0;
        int t1 = (sum - diff) / 2;

        return perfectSum(arr, t1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(nums,target);
    }
};