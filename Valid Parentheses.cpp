#include <vector>
using namespace std;
class Solution {
public:
    char reverseOf(char c){
        if(c=='}'){
            return '{';
        }
        else if(c==')'){
            return '(';
        }
        return '[';
    }
public:
    bool isValid(string s) {
        vector <char> stack;
        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                stack.push_back(c);
            }
            else{
                if(stack.empty()){
                    return false;
                }
                if(stack.back()!=reverseOf(c)){
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty()?true:false;
    }
};