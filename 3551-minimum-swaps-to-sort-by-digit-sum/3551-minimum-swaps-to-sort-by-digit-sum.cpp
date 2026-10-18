class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int,3>> v(n);
        for(int i =0;i<n;i++){
            int digis = 0;
            int x = nums[i];
            while(x > 0){
                digis += x%10;
                x /= 10;
            }
            v[i] = {digis,nums[i],i};
        } 
        sort(v.begin(),v.end());
        vector<bool> visi(n,false);
        int ans =0;
        for(int i =0;i<n;i++){
            if(visi[i] || v[i][2] == i) continue;
            int j = i;
            int len =0;
            while(!visi[j]){
                visi[j] = true;
                j = v[j][2];
                len++;
            }
            ans += len - 1;
        }
        return ans;
    }
};