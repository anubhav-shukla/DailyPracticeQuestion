

#include <bits/stdc++.h>
using namespace std;


vector<vector> outerTrees(vector<vector>& trees) {
vector<vector>ans;
set<pair<int,int>>myset;
map<int,vector>mp;
for(auto it:trees){
mp[it[0]].push_back(it[1]);
}
for(auto &it:mp){
sort(it.second.begin(),it.second.end(),greater());
}

    // for(auto it:mp){
    //    for(auto i:it.second){
    //        cout<<i<<" ";
    //    }
    //    cout<<endl; 
    // }
    auto i=mp.begin()->first;
    for(auto it:mp.begin()->second){
        myset.insert({i,it});
    }
    
    i=(--mp.end())->first;
    for(auto it:(--mp.end())->second){
        myset.insert({i,it});
    }
    
    float slope=0;
    stack<pair<pair<int,int>,float>>st1;
    int a,b;
    for(auto it:mp){
        if(st1.empty()){
            st1.push({{it.first,it.second.front()},-1});
        }
        else if(st1.size()==1){
            a=st1.top().first.first;
            b=st1.top().first.second;
            slope=(float)(b-it.second.front())/(a-it.first);
            st1.push({{it.first,it.second.front()},slope});
        }
        else{
            a=st1.top().first.first;
            b=st1.top().first.second;
            slope=st1.top().second;
            float newSlope=(float)(b-it.second.front())/(a-it.first);
            while(newSlope>slope && st1.size()>1){
                st1.pop();
                a=st1.top().first.first;
                b=st1.top().first.second;
                slope=st1.top().second;
                newSlope=(float)(b-it.second.front())/(a-it.first);
            }
            st1.push({{it.first,it.second.front()},newSlope});
        }
    }
    
    stack<pair<pair<int,int>,float>>st2;
    for(auto it:mp){
        if(st2.empty()){
            st2.push({{it.first,it.second.back()},-1});
        }
        else if(st2.size()==1){
            a=st2.top().first.first;
            b=st2.top().first.second;
            slope=(float)(b-it.second.back())/(a-it.first);
            st2.push({{it.first,it.second.back()},slope});
        }
        else{
            a=st2.top().first.first;
            b=st2.top().first.second;
            slope=st2.top().second;
            float newSlope=(float)(b-it.second.back())/(a-it.first);
            while(newSlope<slope && st2.size()>1){
                st2.pop();
                a=st2.top().first.first;
                b=st2.top().first.second;
                slope=st2.top().second;
                newSlope=(float)(b-it.second.back())/(a-it.first);
            }
            st2.push({{it.first,it.second.back()},newSlope});
        }
    }
    
    
    while(!st1.empty()){
         myset.insert(st1.top().first);
         st1.pop();
    }
    while(!st2.empty()){
         myset.insert(st2.top().first);
         st2.pop();
    }
    
    for(auto it:myset){
        int a=it.first;
        int b=it.second;
        ans.push_back({a,b});
    }
    return ans;
}


