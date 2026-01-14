#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *dmhead = new ListNode(0);
    void addAtHead(int val,ListNode *dmhead) {
        ListNode *s = new ListNode(0);
        s->val = val;
        s->next = dmhead->next;
        dmhead->next = s;
    }
    int len(ListNode *dmhead){
        ListNode *p = dmhead;
        int len=0;
        while(p->next){
            len++;
            p=p->next;
        }
        return len;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *dmheada = new ListNode(0);
        dmheada->next = headA;
        ListNode *dmheadb = new ListNode(0);
        dmheadb->next = headB;
        int lena = len(dmheada);
        int lenb = len(dmheadb);
        int x,i;
        x = abs(lena - lenb);
        ListNode *fast;
        ListNode *slow;
        if(lena > lenb){
            i =0;
            fast = dmheada;
            while(i<x){
                fast = fast->next;
                i++;
            }
            slow = dmheadb;
            
        }
        else if(lenb > lena){
            i = 0;
            fast = dmheadb;
            while(i<x){
                fast = fast->next;
                i++;
            }
            slow = dmheada;
        }
        
        while(slow && fast){
            if(slow->next == fast -> next){
                ListNode *final = slow->next;
                return final;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return NULL;
    }
};
int main(){
    Solution a;
    a.addAtHead(4,a.dmhead);
    a.addAtHead(1,a.dmhead);
    a.addAtHead(8,a.dmhead);
    a.addAtHead(4,a.dmhead);
    a.addAtHead(5,a.dmhead);
    a.print();
    Solution b;
    b.addAtHead(5,b.dmhead);
    b.addAtHead(0,b.dmhead);
    b.addAtHead(1,b.dmhead);

    b.print();
    Solution L;
    L.dmhead = L.getIntersectionNode(a.dmhead->next,b.dmhead->next);

}