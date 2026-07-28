class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
         // set<vector<int>> st; // set jiske andar list store ho.
          vector<vector<int>> ans;
       sort(nums.begin(),nums.end());
       for(int i = 0; i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j =i+1;j<n;j++){
            if(j != i+1 && nums[j] == nums[j-1]) continue;
            long long sum = nums[i] + nums[j];
            long long secondSum = target - (sum);
            int p1 =j+1;
            int p2 =n-1;
            while(p1<p2){
                if(p1<p2 && nums[p1] + nums[p2] == secondSum){
                    vector<int> temp = {nums[i], nums[j],nums[p1], nums[p2]};
                    //sort(temp.begin(), temp.end());
                    //st.insert(temp);
                    ans.push_back(temp);
                    p2--;
                    p1++;
                    while( p1 < p2 && nums[p1] == nums[p1-1]) p1++;
                    while( p1 < p2 && nums[p2] == nums[p2+1]) p2--;

                }
                else if(nums[p1] + nums[p2] > secondSum) p2--;
                else p1++;
            }
        }
       }
        return ans;
    }
};