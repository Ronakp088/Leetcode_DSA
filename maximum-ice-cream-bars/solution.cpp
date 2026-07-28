class Solution {
public:
    int check(vector<int>& costs,int k,int mid){
        long long  sum =0;
        for(int i=0;i<=mid;i++){
            sum += costs[i];
        }
        if(sum < k) return 1;
        if(sum == k) return 2;

        return 0;
    } 
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int low = 0;
        int high = costs.size()-1;
        int ans =0;
        while(low<=high){
            int mid = (low + high) >> 1;
            if(check(costs,coins,mid) == 2) return mid+1;
            else if(check(costs,coins,mid) == 1) {
                ans = max(mid+1,ans);
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
            return ans;
    }
};