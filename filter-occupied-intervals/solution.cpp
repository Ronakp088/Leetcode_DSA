class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>> mearged;
        vector<vector<int>> ans;
        //if(occupiedIntervals.size() ==  1) mearged = occupiedIntervals;
        vector<int> ls;
        ls = occupiedIntervals[0];
        int i =1;
        while(i<occupiedIntervals.size()){
            if(ls[1] + 1 >= occupiedIntervals[i][0]){
                ls[1] = max(ls[1],occupiedIntervals[i][1]);
                i++;
            }
            else{
                mearged.push_back(ls);
                ls = occupiedIntervals[i];
                i++;
            }
        }
        mearged.push_back(ls);
        // int flag = 0;
        // int flag2 =0;
        for (int i = 0; i < mearged.size(); i++) {
            if (mearged[i][1] < freeStart || mearged[i][0] > freeEnd) {
                ans.push_back(mearged[i]);
                continue;
            }
            if (mearged[i][0] < freeStart) {
                ans.push_back({mearged[i][0], freeStart - 1});
            }
            if (mearged[i][1] > freeEnd) {
                ans.push_back({freeEnd + 1, mearged[i][1]});
            }
        }
        return ans;
    }
};