class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        pair<int,int> s = {INT_MAX,-1}; 
        pair<int,int> l = {INT_MIN,-1};
        for(int i =0;i<n;i++){
            if(nums[i] > l.first){
                l = {nums[i],i};
            }
            if(nums[i] < s.first){
                s= {nums[i],i};
            }
        } 
        int k = s.second;
        int h = l.second;
        int mid = n/2;
        int flag =0;
        if(k <= mid && h <= mid) flag =1;
        if(k >= mid && h >= mid) flag =2;
        if(flag == 1){
            return max(h,k) + 1;
        }
        else if(flag == 2){
            return n-min(h,k);
        }
        int one = min(k+1,n-k) + min(h+1,n-h);
        int two = min((max(h,k)+1),n-min(h,k));
        int three = min(one,two);
        return three;
    }
};