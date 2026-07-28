class Solution {
public:
    int maxProduct(int n) {
        int ok = n;
        int count =0;
        while (ok>0){
            ok = ok/10;
            count++;
        }
        int arr[count];
        ok = n;
        int i=0;
        while (ok>0){
            arr[i] = ok%10;
            ok = ok /10;
            i++;
        }
        int maxi = 0;
        for (int j=0; j<count;j++){
            for (int k= j+1; k<count; k++){
                int hehe = arr[j]*arr[k];
                maxi = max(maxi, hehe);
            }
        }
        return maxi;
    }
};