
#include <bits/stdc++.h>
#include <math.h>
using namespace std;


int poorPigs(int buckets, int poisonTime, int totalTime) {
    return ceil(log(buckets) / log(totalTime / poisonTime + 1));
}


int main(){
 int   buckets = 1000,minutesToDie = 15, minutesToTest = 60;
  cout<<poorPigs(buckets,minutesToDie,minutesToTest);

}