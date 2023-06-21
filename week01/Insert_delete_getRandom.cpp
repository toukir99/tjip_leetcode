class RandomizedSet {
public:

    RandomizedSet() {
        
    }
    bool insert(int val) {
        if(um.find(val)!=um.end())
        {
             return false;        
        }
        else{
            v.push_back(val);
            um[val]=v.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
       if(um.find(val)!=um.end())
        {
            int last=v.back();
            um[last]=um[val];
            v[um[val]]=last;
            v.pop_back();
            um.erase(val);
            return true;        
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    vector<int>v;
    unordered_map<int, int> um;
};
