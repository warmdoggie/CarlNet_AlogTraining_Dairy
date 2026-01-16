#include <iostream>
#include <string>
using namespace std;

void revers(string &s,int left,int right){
    while(left < right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
}
string delete_blank(string s){
    string result;
    int i = 0;
    while(i<s.size() && s[i] == ' '){
        i++;
    }
    int flag;
    for(;i<s.size();i++){
        if(s[i] != ' '){
            result.push_back(s[i]);
            flag = 0;
        }
        else if(s[i] == ' '&& flag == 0){
            result.push_back(s[i]);
            flag = 1;
        }    
    }
    return result;
}
string reverseWords(string s) {
    // 翻转整个s
    revers(s,0,s.size() - 1);
    //删除多余空格
    string result= delete_blank(s);
    int low = -1,high = -1;
    int flag = 0;
    for(int i = 0;i<result.size();i++){
        if(result[i] != ' ' && flag == 0){
            low = i;
            flag = 1;
        }
        else if(flag == 1 && result[i] != ' '&& (result[i+1] == ' ' || result[i+1] == '\0')){
            high = i;
            flag = 0;
        }
        if(low != -1 && high != -1){
            revers(result,low,high);
            low = -1;
            high = -1;
        }
    }
    return result;
    
}
// string reverseWords(string s) {


// }
int main(){
    string s;
    getline(cin >> ws,s);

    string a = reverseWords(s); 

    cout << a << endl;
    cout << a.size() << endl;
    return 0;
}