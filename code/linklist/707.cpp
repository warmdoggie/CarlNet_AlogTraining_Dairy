#include <iostream>
using namespace std;


class MyLinkedList {
public:
    // 定义链表结构体
    struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode(int val) : val(val), next(nullptr) {}
    }*_dummyhead;
    
    int _size;
    MyLinkedList() {
        _dummyhead = new LinkNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= _size)return -1;

        LinkNode *p = _dummyhead;
        for(int i = -1;i<index;i++)
            p = p->next;
        
        return p->val;
    }
    
    void addAtHead(int val) {
        LinkNode *s = new LinkNode(0);
        s->val = val;
        s->next = _dummyhead->next;
        _dummyhead->next = s;
        _size++;
    
    }
    
    void addAtTail(int val) {
        LinkNode *p = _dummyhead;
        LinkNode *s = new LinkNode(0);
        s->val = val;
        while(p -> next != nullptr)
            p = p->next;
        p->next = s;
        s->next = nullptr;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 )index = 0;
        if (index > _size) return;
        LinkNode *p = _dummyhead;
        LinkNode *s = new LinkNode(0);
        s->val = val;
        for(int i = 0;i<index ;i++)
            p = p->next;
        s->next = p->next;
        p->next = s;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 ||index >= _size || _dummyhead->next == nullptr)return;
        LinkNode *p = _dummyhead;
        int i;
        for(i = -1;i<index-1;i++)
            p=p->next;
        LinkNode *q = p->next;
        if(i ==_size-1){
            p->next = nullptr;
        }
        else{
            p->next = q->next;
        }
        delete q;
        _size--;
    }
    void print(){
        cout << "[";
        LinkNode *p = _dummyhead;
        while(p->next!=nullptr){
            p=p->next;
            cout << p->val << " ";
        }
        cout << "]" << "/n";
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    // 模拟你给的 LeetCode 操作序列：
    // ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
    // [[], [1], [3], [1, 2], [1], [1], [1]]

    MyLinkedList L;

    L.addAtHead(1);
    L.print();
    L.addAtTail(3);
    L.print();
    L.addAtIndex(1,2);
    L.print();
    int a = L.get(1);
    cout << "L.get(1)= " << a << "/n";
    L.deleteAtIndex(1);
    a = L.get(1);
    cout << "L.get(5)= " << a << "/n";
    

    

    return 0;
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */