#include <iostream>
#include <stack>
using namespace std;

int findMaxLen(string str){
    stack<int> stack;
    stack.push(-1);
    int len=0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '('){
            stack.push(i);

        }
        else{
            stack.pop();

            if(stack.empty()){
                stack.push(i);
                continue;
            }
            int curr_len = i-stack.top();
            if(len < curr_len){
                len = curr_len;
            }

        }
    }
    return len;
}
int main(){
    cout<< findMaxLen("((()")<<endl;
}