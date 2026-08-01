class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int maxlen =0;
        int i =0;
        int j= 0;
        int cnt =0;
        while(j<n && i<n){
            j = i + nums[i];
            if(j >= n-1) return cnt+1;
            else {int idx =0;
            int maxi =i + nums[i];
            int flag =0;
            for(int k =i+1;k<=j;k++){
                if(k + nums[k] > maxi){
                    maxi  = k + nums[k];
                    idx =k;
                    flag =1;
                }
            }
           if(flag) i=idx;
           else i = maxi;
            cnt++;}
        }
       
        return cnt;
    }
};