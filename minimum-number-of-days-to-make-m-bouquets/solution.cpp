class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, long long mid){
        int cnt = 0, cnt2 = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid)  
                cnt++;
            else
                cnt = 0;          
            
            if(cnt == k){         
                cnt2++;
                cnt = 0;          
            }
        }
        return cnt2 >= m;          
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long flowers = (long long)m * k;
        if(flowers > bloomDay.size()) return -1;
        
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        long long low  = *min_element(bloomDay.begin(), bloomDay.end());
        long long ans = high;
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(check(bloomDay, m, k, mid)){
                ans = mid;
                high = mid - 1;  
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};