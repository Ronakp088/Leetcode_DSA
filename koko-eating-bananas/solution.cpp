class Solution {
public:
    long long  checkFunc(long long k,vector<int>& piles){
        long long time =0;
        for(int i=0;i<piles.size();i++){
            time += (piles[i] + k - 1) / k;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, long long h) {
        long long high = *max_element(piles.begin(), piles.end());       
        long long  low = 1;
        long long ans =high;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(checkFunc(mid,piles) <= h){
                ans = mid;
                high =mid -1;
            }
            else low = mid+1;
        }
        return ans;
    }
};