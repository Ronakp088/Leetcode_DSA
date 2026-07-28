class Solution {
public:

    int trap(vector<int>& height) {
        int ans =0;
        int Lmax = 0;
        int Rmax =0;
        int p1 =0; // left pointer 
        int p2 = height.size()-1; // right pointer

        while(p1<p2){
            if(height[p1] < height[p2]){
                if(Lmax > height[p1]) // means left side mei wall hai pani kko rok ne ke liye 
                {
                    ans += Lmax - height[p1];
                }
                else Lmax = height[p1];
                p1++;
            }
            else{
                if(Rmax > height[p2]) // right side mei hai pani rook ne ke liye 
                {
                    ans += Rmax - height[p2];
                }
                else Rmax = height[p2];
                p2--;
            }
        }
        return ans;
    }
};