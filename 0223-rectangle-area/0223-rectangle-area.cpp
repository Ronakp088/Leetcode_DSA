class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs((ay2-ay1)*(ax1-ax2));
        int area2 = abs((by2-by1)*(bx2-bx1));
        if(ay1>by2 && ay2 > by2) return area1+area2;
        if(by1>ay2 && by2 > ay2) return area1+area2;
        if(bx1>ax2 && bx2 > ax2) return area1+area2;
        if(ax1>bx2 && ax2 > bx2) return area1+area2;
        
        int height = abs(min(ay2,by2) - max(ay1,by1));
        int len = abs(min(ax2,bx2) - max(ax1,bx1));
        
        return area1 + area2 - (len*height);

    }
};