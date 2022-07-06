  #include <bits/stdc++.h>
  using namespace std;
  int fib(int N) {
        double phi = (sqrt(5) + 1) / 2;     
        return round(pow(phi, N) / sqrt(5));
    }
    
        
    int main(){
        cout<<fib(4);
    }