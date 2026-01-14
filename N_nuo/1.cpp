#include <iostream>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	int count=0;
	for(int i = a;i < b+1;i++){
		if((i != 1)&&(i == 2 || i % 2 == 1))
            count++;
	}
	cout << count;
	return 0;
}