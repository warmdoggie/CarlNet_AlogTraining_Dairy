#include <iostream>
using namespace std;


class Solution {
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val) : val(val), next(nullptr){}
    };
    ListNode *dmhead = new ListNode(0);
    void addAtHead(int val,ListNode *dmhead) {
        ListNode *s = new ListNode(0);
        s->val = val;
        s->next = dmhead->next;
        dmhead->next = s;
    }
    void print(){
        ListNode *p = dmhead;
        if(p->next==nullptr)return;
        while(p->next!=nullptr){
            p = p->next;
            cout << p->val << " ";
        }
        cout << "\n";
    }
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return NULL;
        ListNode *dmhead = new ListNode(0);
        dmhead->next = head;
        ListNode *p = dmhead;
        int i = -1,j = -1;
        while(p->next){
            p = p->next;
            i++;
            ListNode *s = p->next;
            while(s){
                if(s->next == p){
                    j = i;
                    break;
                }
                s = s->next;
            }
            if(j != -1)break;
        }
        if(j == -1)return NULL;
        else
            return p;
    }
};
int main(){
    Solution L;
    L.addAtHead(1,L.dmhead);
    L.addAtHead(2,L.dmhead);
    L.addAtHead(3,L.dmhead);
    L.addAtHead(4,L.dmhead);
    L.addAtHead(5,L.dmhead);
    L.print();
    int n;
    cout << "the number you delete: ";
    cin >> n;

    L.print();
}
