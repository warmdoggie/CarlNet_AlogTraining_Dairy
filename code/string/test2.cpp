#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a;
    cin >> a;
    vector<int> num;
    for(int i = 0;i<a;i++){
        int n;
        cin >> n;
        num.push_back(n);
    }

    int len = num.size();
    cout <<len <<endl;
}
