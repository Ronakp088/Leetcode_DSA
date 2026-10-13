class Solution {
public:
    long long maxAlternatingSum(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end(), [](int a, int b){
            return abs(a) > abs(b);     
        });
        long long ans =0; 
        int i =0;
        int j = n-1;
        while(i<j){
            ans += 1LL*v[i]*v[i];
            ans -= 1LL*v[j]*v[j];
            i++;
            j--;
        }
        if( i == j){
            ans += 1LL*v[i]*v[i];
        }

        return ans;
    }
};