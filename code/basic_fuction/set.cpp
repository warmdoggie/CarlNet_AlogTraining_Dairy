#include <iostream>
#include <set>
using namespace std;
int main(void){
    set<string> s;
    // 插入相同字符串会被忽视
    cout << s.size() <<endl;
    s.insert("string");
    cout << s.size() <<endl;
    s.insert("abc");
    cout << s.size() <<endl;
    s.insert("string");
    cout << s.size() <<endl;


}