class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int n = p.size();
        if( n == 1) return 1;
        int e= p[0][1];
        int ans = 0;
        int s = p[0][0];
        int c = 0;
        for(int i =1; i<n;i++){
            if(p[i][0]  >= s && p[i][1] <= e){ 
                s = p[i][0];
                e = p[i][1];
                c++;
            }
            else if(p[i][0] <= e && p[i][1] > e){
                s = p[i][0];
                c++;
            }
            else if(p[i][0] > e){
                ans++;
                c =0;
                s = p[i][0];
                e = p[i][1];
            }
        }
        ans++;

        return ans;
    }
};