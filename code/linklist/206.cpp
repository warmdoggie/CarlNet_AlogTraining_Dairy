#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val) : val(val), next(nullptr){}
    };
    int size;

    ListNode *dmhead = new ListNode(0);
    void addAtHead(int val,ListNode *dmhead) {
        ListNode *s = new ListNode(0);
        s->val = val;
        s->next = dmhead->next;
        dmhead->next = s;
    }
    // void addin(int n){
    //     for(int i = 0;i<n;i++){
    //         int a;
    //         cin >> a;
    //         addAtHead(a);
    //     }
    // }
    void print(){
        ListNode *p = dmhead;
        if(p->next==nullptr)return;
        while(p->next!=nullptr){
            p = p->next;
            cout << p->val << " ";
        }
        cout << "\n";
    }
    ListNode* reverseList(ListNode* dmhead) {
        if(dmhead == nullptr)return nullptr;
        Solution N;
        ListNode *p = dmhead;
        while(p->next != nullptr){
            p = p->next;
            N.addAtHead(p->val,N.dmhead);
        }
        return N.dmhead->next;
    }

    
};
int main(){
    // int n;
    // cout << "input numlen:";
    // cin >> n;
    Solution L;
    L.addAtHead(5,L.dmhead);
    L.addAtHead(4,L.dmhead);
    L.addAtHead(3,L.dmhead);
    L.print();
    L.reverseList(L.dmhead);
    L.print();

}