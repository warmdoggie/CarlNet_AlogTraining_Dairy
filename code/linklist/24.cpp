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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *dmhead = new ListNode(0);
        dmhead ->next = head;
        ListNode *pre = dmhead;
        ListNode *cur = head;
        ListNode *back = head->next;
        int flag = 0;
        while(cur && back){


            pre->next = back;
            cur->next = back->next;
            back->next = cur;
            if(flag == 0){
                flag = 1;
                head = pre->next;
            }
            pre = cur;
            if(!cur->next)return head;
            cur = cur->next;
            back = cur->next;
        }
        return dmhead->next;
    }
        // ListNode dummy(0);
        // dummy.next = head;
        // ListNode* prev = &dummy;
        // while (prev->next && prev->next->next) {
        //     ListNode* cur = prev->next;
        //     ListNode* back = cur->next;
        //     cur->next = back->next;
        //     back->next = cur;
        //     prev->next = back;
        //     prev = cur;
        // }
        // return dummy.next;
    void print(){
        ListNode *p = dmhead;
        if(p->next==nullptr)return;
        while(p->next!=nullptr){
            p = p->next;
            cout << p->val << " ";
        }
        cout << "\n";
    }
};
int main(){
    Solution L;
    L.addAtHead(3,L.dmhead);
    L.addAtHead(4,L.dmhead);
    L.addAtHead(1,L.dmhead);
    L.addAtHead(2,L.dmhead);
    L.print();
    L.dmhead->next=L.swapPairs(L.dmhead->next);
    L.print();
}