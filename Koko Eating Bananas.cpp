#define ll long long
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll l = 1, r = 1e9;
        while(l <= r) {
            ll tot = 0, mid = (l + r) / 2;
            for(int i=0; i<piles.size(); i++) tot += ceil(1.0 * piles[i] / mid);
            if(tot > h) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};