#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int, string> map;
    map[1] = "h";
    map[2] = "b";
    cout << map[1] <<endl;
}
