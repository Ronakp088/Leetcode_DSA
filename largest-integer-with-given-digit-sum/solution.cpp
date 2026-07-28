class Solution {
public:
    int  largestInteger(int n, int s) {
        if(s == 0)return 0;
        int p =0;
        int check =0;
        if(s<=9){
            p = p*10 + s;
            n--;
            while(n>0){
                p = p*10 + 0;
                n--;
            }
        }
        
       else {
           while(s>=9){
            p = p*10 +9;
            s-=9;
            check++;
            if(check > n)return -1;
            else if(check == n && s>0) return -1;
        }
        while(check != n) {
            p = p*10 + s;
            s = 0;
            check++;
        }
            }

        return p;
    }
};