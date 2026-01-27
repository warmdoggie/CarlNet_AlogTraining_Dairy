#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string removeDuplicates(string s) {
    stack<char> res;
    string b;
    for(char c : s){
        if(res.empty()){
            res.push(c);
        }
        else{
            char a = res.top();
            if(a == c){
                res.pop();
            }
            else
                res.push(c);
        }
    }

    while(!res.empty()){
        b += res.top();
        res.pop();
    }
    
    reverse(b.begin(),b.end());
    return b;
    
}

int main(){

}