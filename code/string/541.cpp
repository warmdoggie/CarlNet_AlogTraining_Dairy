#include <iostream>

using namespace std;
class Solution {
public:
    void rev(string &s,int left,int right) {
        while(left <= right){
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            left++;
            right--;
        }
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        if(n > 1 && n < k){
            rev(s, 0, n-1);
        }  
        else if(n > k && n<2*k){
            rev(s,0,k-1);
        }

        int start = 0;
        int left;
        while(n > 2*k){
            rev(s,start,k-1 +start);
            left = n - 2 * k;
            n = left;
            if(left < k) {
                rev(s,2*k+start,s.size()-1);
            }
            else if(left < 2*k && left >= k){
                rev(s,2*k+start,2*k + k-1 +start);
            }  
            else{
                start += 2*k;
            }
        }
        return s;

    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution L;
    string s ;
    cout << "input s:" << endl;
    cin >> s ;
    string t = L.reverseStr(s, 20);
    cout << t;

}