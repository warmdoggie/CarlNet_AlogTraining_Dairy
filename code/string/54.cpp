#include <iostream>
using namespace std;

string changeNum(string &s){
    string n;
    for(char a : s){
        if(a >= '0' && a <= 57){
            n+="number";
            //n.append("number");
        }
        else{
            //push_back只能加一个字符
            n.push_back(a);
        }
    }
    return n;
}
int main(){
    string s;
    cin >> s;
    string a = changeNum(s);
    cout<< a;


}