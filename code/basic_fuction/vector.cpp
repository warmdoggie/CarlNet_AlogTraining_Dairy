#include <iostream>
#include <vector>
using namespace std;
int main(void){
    vector<int>num;

    cout << "length = " << num.size() <<endl;
    num.push_back(1);
    cout << "length = " << num.size() <<endl;
    return 0;
}