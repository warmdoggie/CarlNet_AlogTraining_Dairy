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
    //暴力解法
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode *dmhead = new ListNode(0);
    //     dmhead->next = head;
    //     if(!head)return head;
    //     ListNode *p = dmhead;
    //     int len = 0;
    //     while(p->next){
    //         p = p->next;
    //         len++;
    //     }
    //     int i;
    //     for(i = 0,p=dmhead;i<len - n;i++){
    //         p = p->next;
    //     }
    //     ListNode *s = p->next;
    //     p->next = s->next;
    //     delete s;
    //     head = dmhead->next;
    //     return head;
    // }
    //双指针法
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dmhead = new ListNode(0);
        dmhead->next = head;
        ListNode *fast = dmhead ,*slow = dmhead;
        int i=0;
        while(i<=n){
            fast = fast->next;
            i++;
        }
        while(fast!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *q = slow->next;
        if(!q->next){
            slow->next = nullptr;
        }
        else{
            slow->next = q->next;
        }
        delete q;
        return dmhead->next;
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
    L.dmhead->next = L.removeNthFromEnd(L.dmhead->next,n);
    L.print();
}