class MyLinkedList {
public:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummyhead = new LinkedNode(0);
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index > (size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = dummyhead->next;
        while(index>0)
        {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
         LinkedNode* newNode = new LinkedNode(val);
        newNode->next = dummyhead->next;
        dummyhead->next = newNode;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* newnode = new LinkedNode(val);
        LinkedNode* cur = dummyhead;
        while(cur->next!=nullptr){
        cur=cur->next;}
        cur->next = newnode;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
          if (index > size) {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummyhead;
        while(index>0) {
            cur = cur->next;
            index--;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
         if (index >= size || index < 0) {
            return;
        }
        LinkedNode* cur = dummyhead;
        while(index>0) {
            cur = cur ->next;
            index--;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;

    }
    private:
    int size;
    LinkedNode* dummyhead;
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