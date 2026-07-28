class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        int l = 0;
        int r =0;
        int Maxlen = 0;
        while(r<n){
          mpp[arr[r]]++;
          if(mpp.size() > 2){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
          }
          if(mpp.size() <= 2){
            Maxlen = max(Maxlen,r-l+1);
          }
            r++;
        }
        return Maxlen;
        
    }
};