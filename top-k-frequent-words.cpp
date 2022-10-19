

#include <bits/stdc++.h>
using namespace std;

  static bool comp(pair<string,int> a, pair<string,int> b){
        if(a.second==b.second) return a.first<b.first;
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto i: words) mp[i]++;
        vector<pair<string,int>> v;
        for(auto i: mp) v.push_back(i);
        sort(v.begin(), v.end(), comp);
        vector<string>ans;
        for(int i=0;i<k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }

   