class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newinterval) {
        int n = interval.size();
        int idx1 =-1;
        int idx2 = -1;
        int flag =0;
        for(int i=0;i<n;i++){
            if(interval[i][1] > newinterval[0]){
                idx1 = i;
                break;
            }
            else if(interval[i][1] == newinterval[0]){
                idx1 =i;
                flag =1;
                break;
            }
        }
        if(idx1 == -1){
            vector<vector<int>> ans1(interval.begin(),interval.end());
            ans1.push_back(newinterval);
            return ans1;
        }

        for(int i = idx1;i<n;i++){
            if(interval[i][0] > newinterval[1]){
                idx2 = i-1;
                break;
            }
            else if(interval[i][0] == newinterval[1]){
                idx2 =i;
                break;
            }
        }
        if( idx2 == -1){
            vector<vector<int>> ans;
            if(interval[idx1][0] > newinterval[1]){
                for(int i=0;i<idx1;i++){
                    ans.push_back(interval[i]);
                }
                ans.push_back(newinterval);
                for(int i=idx1;i<n;i++){
                    ans.push_back(interval[i]);
                }
            }
            else if(interval[idx1][1] == newinterval[0]){
                for(int i=0;i<idx1;i++){
                    ans.push_back(interval[i]);
                }
                ans.push_back({min(interval[idx1][0],newinterval[0]), max(interval[n-1][1],newinterval[1])});
            }
            else if(interval[idx1][1] < newinterval[0]){
                for(int i =0;i<=idx1;i++){
                    ans.push_back(interval[i]);
                }
                if(idx1+1<n){
                    ans.push_back({min(interval[idx1+1][0],newinterval[0]),newinterval[1]});
                }
                else{
                    ans.push_back(newinterval);
                }
            }
            else {
                for(int i=0;i<idx1;i++){
                    ans.push_back(interval[i]);
                }
                ans.push_back({min(interval[idx1][0],newinterval[0]), max(interval[n-1][1],newinterval[1])});
            }
            return ans;
        }
        vector<vector<int>> ans2;
        if(flag){
            for(int i =0;i<= idx1-1;i++){
                ans2.push_back(interval[i]);
            }
            ans2.push_back({interval[idx1][0],max(interval[idx2][1],newinterval[1])});
            for(int i =idx2+1;i<n;i++){
                ans2.push_back(interval[i]);
            }
        }
        else {
            for(int i =0;i<= idx1-1;i++){
                ans2.push_back(interval[i]);
            }
            ans2.push_back({min(interval[idx1][0],newinterval[0]),max(interval[idx2][1],newinterval[1])});
            for(int i =idx2+1;i<n;i++){
                ans2.push_back(interval[i]);
            }
        }
        return ans2;
    }
};