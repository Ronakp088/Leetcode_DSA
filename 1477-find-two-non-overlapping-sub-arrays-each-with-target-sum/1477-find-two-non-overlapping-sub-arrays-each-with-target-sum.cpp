class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int r = 0;
        vector<pair<int,pair<int,int>>> v;
        int sum = 0;
        while(r < n){
            sum += arr[r];
            while(sum > target){
                sum -= arr[l];
                l++;
            }
            if(sum == target){
                v.push_back({r-l+1,{l,r}});
                sum -= arr[l];
                l++;
            }
            r++;
        }

        int ans = INT_MAX;
        int bestLeft = INT_MAX;
        int k = 0;
        for(int j = 0; j < (int)v.size(); j++){
            while(k < j && v[k].second.second < v[j].second.first){
                bestLeft = min(bestLeft, v[k].first);
                k++;
            }
            if(bestLeft != INT_MAX){
                ans = min(ans, bestLeft + v[j].first);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};