#include <iostream>
using namespace std;
int main(){
	int count = 0;
	for(int i = 100;i<1001;i++){
		if(i%5==0&&i%6==0){
			count++;
			cout << i ;
			if(count != 10)
				cout << " ";
			else{
                cout << "\n";
                count = 0;
            }
				
		}
	}
}