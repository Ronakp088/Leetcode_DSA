class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r-l+1;
        int count =0;
        for(int i = 0;(long long)pow(i,k)<=r;i++){
            if((long long)pow(i,k) >=l) count++;
        }
        return count;
    }
};