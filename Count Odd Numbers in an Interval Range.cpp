class Solution {
public:
    int countOdds(int low, int high) {
        int x=(high-low+1);
        if(x%2==0 || low%2==0){return x/2;}
        return x/2 +1;
    }
};