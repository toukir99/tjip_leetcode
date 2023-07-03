class MyLinkedList {
private:
    class node{
    public:
        int value;
        node* next;
        node(int _value,node* _next)
        {
            value=_value;
            next=_next;
        }
    };

    int len;
    node* head=nullptr; //DUMMY HEAD

public:
    MyLinkedList() {
        len=0;
        head=new node(0, nullptr);
    }
    
    int get(int index) {
        if(len<=index || 0>index) return -1;
        auto curr=head->next;
        while(index--)
        {
            curr=curr->next;
        }
        return curr->value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>len) return;
        auto curr= head;
        while(index--){
            curr=curr->next;
        }
        auto nxt=curr->next;
        curr->next= new node(val, nullptr);
        curr->next->next=nxt;
        len++;
        
    }
    
    void deleteAtIndex(int index) {
        if(len<=index || 0>index) return;
        auto curr= head;
        while(index--){
            curr=curr->next;
        }
        auto tobeRemoved=curr->next;
        curr->next=curr->next->next;
        delete(tobeRemoved);
        len--;
    }
};

