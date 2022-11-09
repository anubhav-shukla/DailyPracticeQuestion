

#include <bits/stdc++.h> 
using namespace std;

 stack<pair<int, int>> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int result = 1;
        while(!s.empty() && s.top().first <= price)
        {
            auto x = s.top();
            s.pop();
            int first = x.first;
            int second = x.second;
            result += second;
        }
        
        s.push({price, result});
        return result;
    }

    int main(){
        
    }