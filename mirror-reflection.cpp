#include <bits/stdc++.h>
using namespace std;



int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0){ 
            p/=2;
            q/=2;
        }
        return 1 - p % 2 + q % 2;
    }

    int main(){
        cout<<mirrorReflection(2,1);
    }