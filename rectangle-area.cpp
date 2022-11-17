#include <bits/stdc++.h>
using namespace std;





int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //find area of first rectangle
        int l1 = ax2 - ax1;
        int b1 = ay2 - ay1;
        int A1 = l1*b1;
        
        // find area of second rectangle
        int l2 = bx2 -bx1;
        int b2 = by2 -by1;
        int A2 = l2*b2;
        
        
        
        int A3 = 0;
        // find area of intersection
        if(bx1<=ax2 && bx2>=ax1 && by1<=ay2 && by2>=ay1)
        {
           int l = min(ax2,bx2) - max(ax1,bx1);
           int b = min(ay2,by2) - max(ay1,by1);
           A3 += l*b;
        }
        
        return A1 + A2 - A3;
    }


    int main(){
        int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
         cout<<computeArea(-3,0,3,4,0,-1,9,2);
    }