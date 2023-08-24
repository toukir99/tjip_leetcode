//tc: O(1)
//sc: O(capacity) capacity= maximum number of item 

class LRUCache {
private:
    list<int> lru;
    unordered_map<int,int> k_v;
    unordered_map<int,list<int>::iterator> k_loc;
    int cap;
    void updateLRU(int key){
        if(k_v.count(key)){
            lru.erase(k_loc[key]);
        }
        lru.push_back(key);
        k_loc[key]=prev(lru.end());
    }
    void evict(){
        int first_key= lru.front();
        k_v.erase(first_key);
        k_loc.erase(first_key);
        lru.pop_front();
    }
        
public:
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(k_v.count(key)==0) return -1;
        updateLRU(key);
        return k_v[key];
    }
    
    void put(int key, int value) {
        if(k_v.count(key)==0 && lru.size()==cap){
            evict();
        }
        updateLRU(key);
        k_v[key]=value;
    }
};
