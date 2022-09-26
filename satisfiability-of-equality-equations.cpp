#include <bits/stdc++.h>
using namespace std;
  


class Solution {
public:
    int S[26];
    int getR(int cur) {
        while (S[cur] != -1) {
            cur = S[cur];
        }
        return cur;
    }
    void insert(int ai, int bi) {
        int ar = getR(ai);
        int br = getR(bi);
        if (ar != br) {
            S[br] = ar;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        memset(S, -1, sizeof(S));
        for (string s : equations) {
            if (s[1] == '=') {
                if (s[0] == s[3])
                    continue;
                if (s[0] > s[3])
                    insert((s[3] - 'a'), (s[0] - 'a'));
                else
                    insert((s[0] - 'a'), (s[3] - 'a'));
            }
        }
        for (string s : equations) {
            if (s[1] == '!') {
                int ra = getR((s[0] - 'a'));
                int rb = getR((s[3] - 'a'));
                if (ra == rb)
                    return false;
            }
        }
        return true;
    }
};