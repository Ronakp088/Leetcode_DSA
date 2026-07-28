class Solution {
public:
    bool check(vector<int>& weights, int days, int mid) {
        int sum = 0;
        int cnt = 1;  
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > mid) {
                cnt++;       
                sum = 0;      
            }
            sum += weights[i];
        }
        return cnt > days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
       int low = *max_element(weights.begin(), weights.end());
       int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(weights, days, mid)) low = mid + 1;  
            else {
            high = mid - 1;  
            ans = mid;
                }
        }
        return ans;
    }
};