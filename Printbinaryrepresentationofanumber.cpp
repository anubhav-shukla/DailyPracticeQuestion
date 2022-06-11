#include<iostream>
#include<string>

using namespace std;

string toBinary(unsigned n){
    if(n==0){
        return "";

    }
    return toBinary(n/2)+ to_string(n%2);

}
int main(){
    int n=20;
    cout<<"The binary representation of"<<n << "is "<< toBinary(n) <<endl;

    return 0;
}