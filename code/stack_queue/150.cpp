#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> r;
    for(string n : tokens){
        
        if(n == "+" || n == "/"|| n == "-"|| n == "*" ){
            if(!r.empty()){
                int b = r.top();
                r.pop();
                int a = r.top();
                r.pop();
                if(n == "+")
                    r.push(a + b);
                else if(n == "-")
                    r.push(a - b);
                else if(n == "*")
                    r.push(a * b);
                else if(n == "/")
                    r.push(a / b);
            }
        }
        else{
            int x = stoi(n);
            r.push(x);
        }
    } 
    if(!r.empty())
        return r.top();
    else
        return 0;
}

int main(){
    vector<string> t;
    int n;
    cin >> n;
    int i = 0;
    while(i<n){
        string x;
        cin >> x;
        t.push_back(x);
        i++;
    }
    cout << evalRPN(t) << endl;


        
}