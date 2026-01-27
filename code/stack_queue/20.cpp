#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s){
    stack<char> a;
    char j;
    for(char i : s){
        if(i == '(' || i == '{' || i == '['){
            a.push(i);
        }
        else{
            if(!a.empty()){
                j = a.top();
                if((j == '('&&i != ')')||(j == '{'&&i != '}')||(j == '['&&i != ']'))
                    return false;
                a.pop();
            } 
            else
                return false;
        }
    }
    if(a.empty())
        return true;
    else
        return false;
}
int main(){
    string s;
    cin >> s;
    cout << isValid(s) ;
}