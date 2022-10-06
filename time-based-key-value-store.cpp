#include <bits/stdc++.h>
 
using namespace std;
 

class TimeMap {
public:
unordered_map<string, map<int, string>> keys;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keys[key][timestamp] = value;
    // inserting into unordered_map O(1)
    // inserting into map O(log n)
    // due to binary search on the tree.
    }
    
    string get(string key, int timestamp) {
        if (keys.count(key)) {
            auto& map = keys[key]; // taking from unordered_map O(1)
            auto it = map.upper_bound(timestamp); // taking from map O(log n)
                          // due to binary search on the tree.
            if (it == map.begin()) {
                return "";
            }
            return (--it)->second;
        }
        return "";
    }
};
