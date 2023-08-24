//tc: O(n)
//sc: O(n)

class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
         remove(key);
         int H= calculateHash(key);
         auto node= new Node(key,value,mapping[H]);
         mapping[H]=node; 
    }
    
    int get(int key) {
         int H= calculateHash(key);
         auto node= mapping[H];
         while(node)
         {
             if(node->key==key)
             {
                 return node->value;
             }
             node=node->next;
         }
         return -1;
    }
    
    void remove(int key) {
         int H= calculateHash(key);
         auto node= mapping[H];
         if(node==nullptr){
             return;
         }
         if(node->key==key)
         {
             mapping[H]= node->next;
             delete node;
             return;
         }
         while(node && node->next){
             if(node->next->key==key)
             {
                 auto temp=node->next;
                 node->next=temp->next;
                 delete temp;
             }
             node=node->next;
         }
    }
private:
    class Node{
        public:
        int key,value;
        Node* next;
        Node (int k,int v, Node* nxt){
            key=k;
            value=v;
            next=nxt;
        }
    };
    const static int CAPACITY= 1991;
    const static int BASE= 997;
    const static int OFFSET= 1937;
    Node* mapping[CAPACITY]={};
    int calculateHash(int key){
        return ((key * BASE) + OFFSET) % CAPACITY;
    }
};
